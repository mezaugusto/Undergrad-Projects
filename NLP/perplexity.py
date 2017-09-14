"""
Augusto Meza Peña
Tarea 2
Smoothing
"""

from nltk import word_tokenize
from nltk.collocations import BigramCollocationFinder
from nltk.stem import SnowballStemmer
from unicodedata import category
from sys import maxunicode
from os import walk
from nltk.probability import FreqDist
from numpy import zeros as npZeros, nditer as npIterator, set_printoptions, where as npWhere, isclose as npIsClose
from math import log2, isclose
from collections import defaultdict
from fractions import Fraction


def vocab_dict():
    vocab = defaultdict()
    vocab.default_factory = lambda: len(vocab)
    return vocab


def text2numba(documents, vocab):
    for doc in documents:
        yield [vocab[w] for w in doc]

# Save all Unicode characters for punctuation in a list
punctuation = [char for char in range(maxunicode) if category(chr(char)).startswith('P')]


class Corpus:
    def __init__(self, path, encoding, input_type, lam=1):
        """
        Class that process a Corpus and obtains useful information
        :param path: path to the file or directory to process
        :param encoding: string with the encoding
        :param input_type: either 'file' or 'directory' depending on path
        :param lam: lambda for the model, defaults to laplace smoothing
        """
        self.encoding = encoding
        self.text = ''  # files are small so we can save them in a String
        self.stems = dict()
        self.tokens = None
        self.lam = lam
        if input_type == 'file':
            self.source = path
            self._retrieve_single_file()
        else:
            self.directory_path = path
            self._retrieve_texts_directory()

        self._clean_and_tokenize()
        self._obtain_stems()
        self._getFrequencies()
        for wi in self.stems:
            print(wi)
        exit()
        print("File correctly processed")

    def _retrieve_single_file(self, filename=''):
        filename = (self.directory_path + '/' + filename) if hasattr(self, 'directory_path') else self.source
        with open(filename, encoding=self.encoding) as currentfile:
            for line in currentfile:
                self.text += line

    def _retrieve_texts_directory(self):
        """ Obtaings all the files in the given directory and attempts to join them to the corpus"""
        filenames = self._files_from_directory()
        for filename in filenames:
            self._retrieve_single_file(filename)

    def _files_from_directory(self):
        """Crawls to only the root folder looking for any files"""
        f = []
        for (dirpath, dirnames, filenames) in walk(self.directory_path):
            f.extend(filenames)
            break
        return f

    def _clean_and_tokenize(self):
        no_punctuation = self.text.translate(dict.fromkeys(punctuation))
        self.tokens = word_tokenize(no_punctuation.lower())

    def _obtain_stems(self):
        stemmer = SnowballStemmer("spanish")
        self.types = set(self.tokens)
        for token in self.types:
            self.stems.update({token: stemmer.stem(token)})

    def _getFrequencies(self):
        """Retrieves the text from all the files, strips punctuation and sets lowercase,
           then tokenizes the String and obtains the types
           after that ir obtains the stem of all the types"""
        stemmed_text = [self.stems[token] for token in self.tokens]

        self.bigram_freq = BigramCollocationFinder.from_words(stemmed_text).ngram_fd
        self.stem_freq = FreqDist(stemmed_token for stemmed_token in stemmed_text)

        self.stem2id = vocab_dict()
        self.stem_in_position = list(text2numba([stemmed_text], self.stem2id))
        self.id2stem = list(self.stem2id.keys())
        self.vocab_length = len(self.stem2id)
        self.first_stem = self.id2stem[self.stem_in_position[0][0]]
        self.last_stem_id = self.stem_in_position[0][-1]
        self._getModel()

    def _getModel(self, vocab_length=None, id2stem=None, lam=None):
        vocab_length = self.vocab_length if vocab_length is None else vocab_length  # reduce verbosity
        id2stem = self.id2stem if id2stem is None else id2stem
        lam = self.lam if lam is None else lam

        tran_prob_matrix = npZeros((vocab_length, vocab_length))  # fill bigram probabilities matrix
        elements = npIterator(tran_prob_matrix, op_flags=['writeonly'], flags=['multi_index'])
        while not elements.finished:
            i, j = elements.multi_index
            wi, wj = id2stem[i], id2stem[j]
            fr_wi_and_wj = self.bigram_freq[(wj, wi)]
            elements[0] = (fr_wi_and_wj + lam) / (self.stem_freq[wj] + lam * vocab_length)
            elements.iternext()

        tran_prob_sum = tran_prob_matrix.sum(axis=0)  # check for consistency
        if len(npWhere(npIsClose(tran_prob_sum, [1.0]) is False)) != 1:
            print("Sum of columns:", tran_prob_sum)
            print("Error: Probability matrix of bigrams is not coherent, ones != 1")
            exit(1)
        elif tran_prob_sum.argmin() != self.last_stem_id:
            print("Sum of columns:", tran_prob_sum)
            print("Word with the minimum:", id2stem[tran_prob_sum.argmin()])
            print("Error: Probability matrix of bigrams is not coherent, min is not last word")
            exit(1)

        init_prob_matrix = npZeros((1, vocab_length))  # fill initial probabilities matrix
        elements = npIterator(init_prob_matrix, op_flags=['writeonly'], flags=['f_index'])
        while not elements.finished:
            x = elements.index
            wi = id2stem[x]
            fr_wi_initial = 1 if wi == self.first_stem else 0
            elements[0] = (fr_wi_initial + lam) / (1 + lam * vocab_length)
            elements.iternext()

        if not isclose(init_prob_matrix.sum(), 1.0):  # check consistency
            print("Sum of row:", init_prob_matrix.sum())
            print("Error: Probability matrix of initials is not coherent, sum is not close to 1")
            exit(1)

        perplex = 0
        for x in range(vocab_length):
            perplex += log2(init_prob_matrix[0, x])
            for y in range(vocab_length):
                perplex += log2(tran_prob_matrix[x, y])
        self.perplex = perplex / (-1 * vocab_length)

        self.tran_prob_matrix = tran_prob_matrix
        self.init_prob_matrix = init_prob_matrix

    def get_perplexity(self, newlam=None):
        if newlam is not None and newlam != self.lam:
            self.lam = newlam
            self._getModel()
        return "The perplexity of the model with lambda '"+str(self.lam)+"' is of 2 to the power of "+str(self.perplex), (self.lam, self.perplex)

    def bigram_prob(self, word_i, word_j):
        initial = self.init_prob_matrix[0, word_i]
        bigram = self.tran_prob_matrix[word_i, word_j]
        return initial * bigram

    def numTokens(self):
        return 'The corpus has '+str(len(self.tokens))+' tokens'

    def numTypes(self):
        return 'The corpus has '+str(len(self.types))+' types'

corpus = Corpus("examen.txt", 'utf-8', input_type="file")
set_printoptions(formatter={'all': lambda x: str(Fraction(x).limit_denominator())})
for lambd in [1, 0.5, 0.1, 0.01]:
    print(corpus.get_perplexity(lambd)[0])
print(corpus.numTokens())
print(corpus.numTypes())
