

from re import sub,compile   #exoresiones regulares
from nltk.tokenize import TweetTokenizer
import nltk
import unicodedata
from string import digits
from sys import  stdout             #imprimir progreso
from unicodedata import category
from sys import maxunicode


punctuation = [char for char in range(maxunicode) if category(chr(char)).startswith('P')]
punctuation.extend([818,35,36,43,94,96])
punctuation.extend([ord(x) for x in digits])
nus = compile(r'@([^\s]+)')
nur = compile(r'http[s]?://([^\s]+)')
nre = compile(r'((\w)\2{2,})')

def file_len(fname,encoding):
    i = -1
    with open(fname,encoding=encoding) as f:
        for i, l in enumerate(f):
            pass
    return i + 1

def clean_and_tokenize(chunk):
    """ Limpiar y tokenizar un pedazo del archivo"""
    result = sub(nus, '@USUARIO',chunk.lower())            #cambiar los ususarios por un placeholder
    result = sub(nur, '', result)      #igualmente para las URL's
    result = result.translate(dict.fromkeys(punctuation))
    result = ''.join((c for c in unicodedata.normalize('NFD',result) if unicodedata.category(c) != 'Mn'))
    result = result.replace('es\n','FDTWEET\n')
    result = result.replace('caracterdesaltodelinea','')
    return sub(nre, r'\2_\2', result) #poner un guion

def update_progress(progress):
    """ Actualiza el string de progreso"""
    stdout.write('\rProcesando archivo {:2.2f}%'.format(progress))

def index_big_file(input_file,output_file='index.txt',encoding='utf-8',debug=False):
    """
    Parte el archivo en pedazos y lo va procesando y tokenizando
    cuando termina pone los no hashtag en minuscula y saca los tipos
    y los imprime en un archivo
    :param input_file: Archivo de entrada
    :param output_file: Archivo en el que se guardara el indice
    :param encoding: Codificación de los archivos de entrada y salida
    :param chunk_size_mb: Tamaño en MB del pedazo en que dividira al archivo
    :param debug: Leer solo una parte del Archivo
    :return: Regresa el Indice
    """
    tokens = []
    #lines = file_len(input_file,encoding) #no hay necesidad de hacerlo cada vez
    lines = 1489703
    step = 100 / lines
    current_progress = 0
    tknzr = TweetTokenizer()
    update_progress(0)
    with open(input_file, encoding=encoding) as corpus:
        for chunk in corpus.readlines():
            tokens += tknzr.tokenize(clean_and_tokenize(chunk))
            current_progress += step
            update_progress(current_progress)
            if debug and current_progress > 5:
                break
    #pprint(nltk.FreqDist(words).most_common(50))
    #context = nltk.ContextIndex(words)
    #print(words[1])
    #print(context.common_contexts(words[1]).most_common())
    types = sorted(set(tokens))
    update_progress(100)
    number_of_types = range(len(types))
    index = dict(zip(number_of_types, types))


index = index_big_file(input_file="solo_espanol.txt",debug=False)
