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
import plotly.plotly as py
import plotly.graph_objs as go
from pprint import pprint


# Save all Spanish characters for punctuation in a list
punctuation = [char for char in range(maxunicode) if category(chr(char)).startswith('P')]

class Corpus():
    def __init__(self,directory_path,encoding):
        self.directory_path = directory_path
        self.encoding = encoding
        self.text = ''
        self.tokens = None
        self.types = None
        self.stems = dict()
        self.graph = None
        self.loggraph = None
        self.processFile()
    def processFile(self):
        self.retrieve_text()
        no_punctuation = self.text.translate(dict.fromkeys(punctuation))
        self.tokens = word_tokenize(no_punctuation.lower())
        stemmer = SnowballStemmer("spanish")
        for token in self.tokens:
            self.stems.update({token:stemmer.stem(token)})
        self.obtain_graph()
        print("File correctly processed")

    def retrieve_text(self):
        filenames = self.files_from_directory()
        for filename in filenames:
            with open(self.directory_path+'/'+filename, encoding=self.encoding) as currentfile:
                for line in currentfile:
                    self.text+=line

    def files_from_directory(self):
        f = []
        for (dirpath, dirnames, filenames) in walk(self.directory_path):
            f.extend(filenames)
            break
        return f

    def obtain_graph(self):
        dist = FreqDist(word for word in self.tokens)
        words_tuple = dist.most_common()
        self.types = [word[0] for word in words_tuple]
        y = [word[1] for word in words_tuple]
        self.graph = go.Figure(
            data =
                [go.Scatter(
                x=self.types,
                y=y,
                name='Frequency of words',
                line=dict(
                    color=('rgb(205, 12, 24)'),
                    width=4)
                )]
        )
        self.loggraph = go.Figure(
            data =
                [go.Scatter(
                x=self.types,
                y=y,
                name='Frequency of words in Logaritmic Scale',
                line=dict(
                    color=('rgb(205, 12, 24)'),
                    width=4)
                )],
            layout = go.Layout(
                yaxis=dict(
                type='log',
                autorange=True)
                )
        )

    def numTokens(self):
        return 'The corpus has '+str(len(self.tokens))+' tokens'

    def numTypes(self):
        return 'The corpus has '+str(len(self.types))+' types'

    def plotGraph(self):
        py.plot(self.graph,filename="zipf")

    def plotLogGraph(self):
        py.plot(self.loggraph,filename="zipf")

corpus = Corpus("corpus1",'utf-8')
corpus.plotGraph()