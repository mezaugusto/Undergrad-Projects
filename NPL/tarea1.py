# TODO : Quitar los signos de puntuación del corpus.
# TODO : Obtener el stem de cada token en el corpus.
# TODO : Obtener el número de tokens y tipos del corpus
# TODO : Obtener la gráfica de la distribución de las palabras (curva de Zipf) ordenadas de mayor a menor por sus rangos estadísticos.
# TODO : Obtener la gráfica de la curva de Zipf en escala logarítmica.

from nltk import word_tokenize
from unicodedata import category
from sys import maxunicode

# Save all Spanish characters for punctuation in a list
punctuation = [char for char in range(maxunicode) if category(chr(char)).startswith('P')]
encoding = "utf-8"

class Corpus():
    def __init__(self,filename):
        self.file = open(filename,encoding=encoding)
        self.tokens = None
        self.types = None
        self.stems = dict()
        self.graph = None
        self.log_graph = None
        self.processFile()
    def processFile(self):
        no_punctuation = self.file.read().translate(dict.fromkeys(punctuation))
        self.tokens = word_tokenize(no_punctuation)
        self.types = sorted(set(self.tokens))
        self.file.close()
    def numTokens(self):
        return len(self.tokens)
    def numTypes(self):
        return len(self.types)

# Treat as separate files
texts = [Corpus("corpus1/d_"+str(i+1)+".txt") for i in range(3)]
for text in texts:
    print(text.numTokens())
    print(text.numTypes())