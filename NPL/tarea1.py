"""
Augusto Meza Peña
Tarea 1
Ley de Zipf
"""

# TODO : Quitar los signos de puntuación del corpus.
# TODO : Obtener el stem de cada token en el corpus.
# TODO : Obtener el número de tokens y tipos del corpus
# TODO : Obtener la gráfica de la distribución de las palabras (curva de Zipf) ordenadas de mayor a menor por sus rangos estadísticos.
# TODO : Obtener la gráfica de la curva de Zipf en escala logarítmica.

from nltk import word_tokenize
from nltk.stem import SnowballStemmer
from unicodedata import category
from sys import maxunicode
from os import walk
from nltk.probability import FreqDist
import matplotlib.pyplot as plt
from pprint import pprint


# Save all Unicode characters for punctuation in a list
punctuation = [char for char in range(maxunicode) if category(chr(char)).startswith('P')]

class Corpus():
    def __init__(self,directory_path,encoding):
        """
        Class that process a Corpus and obtains usefull information
        :param directory_path: Relative path to the FOLDER with the txt files
        :param encoding: Encoding of these texts
        """
        self.directory_path = directory_path
        self.encoding = encoding
        self.text = '' #files are small so we can save them in a String
        self.tokens = None
        self.types = None
        self.stems = dict()
        self.freq = None
        self._processFile()
    def _processFile(self):
        """Retrieves the text from all the files, strips punctuation and sets lowercase,
           then tokenizes the String and obtains the types
           after that ir obtains the stem of all the types"""
        self._retrieve_text()
        no_punctuation = self.text.translate(dict.fromkeys(punctuation))
        self.tokens = word_tokenize(no_punctuation.lower())
        stemmer = SnowballStemmer("spanish")
        self.types = set(self.tokens)
        for token in self.types:
            self.stems.update({token:stemmer.stem(token)})
        self._obtain_graphs()
        print("File correctly processed")

    def _retrieve_text(self):
        """ Obtaings all the files in the given directory and attempts to join them to the corpus"""
        filenames = self._files_from_directory()
        for filename in filenames:
            with open(self.directory_path+'/'+filename, encoding=self.encoding) as currentfile:
                for line in currentfile:
                    self.text+=line

    def _files_from_directory(self):
        """Crawls to only the root folder looking for any files"""
        f = []
        for (dirpath, dirnames, filenames) in walk(self.directory_path):
            f.extend(filenames)
            break
        return f

    def _obtain_graphs(self):
        """ Obtains via FreqDist the frequency and then sorts it from the most to the less frequent"""
        dist = FreqDist(word for word in self.tokens)
        words_tuple = dist.most_common()
        self.types = [word[0] for word in words_tuple]
        self.freq = [word[1] for word in words_tuple]
        plt.title('Zipf Distribution')
        plt.ylabel('Frequency')
        plt.xlabel('Words')

    def numTokens(self):
        return 'The corpus has '+str(len(self.tokens))+' tokens'

    def numTypes(self):
        return 'The corpus has '+str(len(self.types))+' types'

    def plotGraph(self):
        plt.plot(self.freq)
        plt.xscale('linear')
        plt.yscale('linear')
        plt.show()

    def plotLogGraph(self):
        plt.plot(self.freq)
        plt.xscale('log')
        plt.yscale('log')
        plt.show()

corpus = Corpus("corpus1",'utf-8')

#pprint(corpus.stems)
print(corpus.numTokens())
print(corpus.numTypes())
#corpus.plotGraph()
#corpus.plotLogGraph()