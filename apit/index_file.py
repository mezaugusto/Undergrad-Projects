from re import sub,compile   #exoresiones regulares
from nltk.tokenize import TweetTokenizer
from sys import  stdout             #imprimir progreso
from os import stat                 #obtener el tamaño del archivo
from pprint import pprint           #imprimir el indice con formato
from unicodedata import category
from sys import maxunicode
from string import digits
import unicodedata

punctuation = [char for char in range(maxunicode) if category(chr(char)).startswith('P')]
punctuation.extend([818,35,36,43,94,96])
punctuation.extend([ord(x) for x in digits])
nus = compile(r'@([^\s]+)')
nur = compile(r'http[s]?://([^\s]+)')
nre = compile(r'((\w)\2{2,})')

def clean_and_tokenize(chunk,tokenizer):
    """ Limpiar y tokenizar un pedazo del archivo"""
    result = sub(nus, '@USUARIO', chunk.lower())  # cambiar los ususarios por un placeholder
    result = sub(nur, '', result)  # igualmente para las URL's
    result = result.translate(dict.fromkeys(punctuation))
    result = ''.join((c for c in unicodedata.normalize('NFD', result) if unicodedata.category(c) != 'Mn'))
    result = result.replace('es\n', 'FDTWEET\n')
    result = result.replace('caracterdesaltodelinea', '')
    return tokenizer.tokenize(sub(nre, r'\2_\2', result))

def update_progress(progress):
    """ Actualiza el string de progreso"""
    stdout.write('\rProcesando archivo {:2.2f}%'.format(progress))

def index_big_file(input_file,output_file='index.txt',encoding='utf-8',chunk_size_mb=1,debug=False):
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
    chunk_size_mb *= 1000000
    tokens = []
    step = 100 / (stat(input_file).st_size / chunk_size_mb)
    current_progress = 0
    tknzr = TweetTokenizer()
    update_progress(0)
    with open(input_file, encoding=encoding) as corpus:
        for chunk in iter(lambda:corpus.read(chunk_size_mb),''):
            tokens+=clean_and_tokenize(chunk,tknzr)
            current_progress += step
            update_progress(current_progress)
            if debug and current_progress > 5:
                break
    with open(output_file, 'w', encoding=encoding) as f:
        types = sorted(set(tokens))
        update_progress(100)
        number_of_types = range(len(types))
        index = dict(zip(number_of_types, types))
        pprint(index, stream=f)
        return index


index = index_big_file(input_file="solo_espanol.txt",chunk_size_mb=1,debug=True)
