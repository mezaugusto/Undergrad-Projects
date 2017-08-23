

from re import sub,M as Multiline   #exoresiones regulares
from nltk.tokenize import TweetTokenizer
from sys import  stdout             #imprimir progreso
from os import stat                 #obtener el tamaño del archivo
from pprint import pprint           #imprimir el indice con formato


def clean_and_tokenize(chunk):
    """ Limpiar y tokenizar un pedazo del archivo"""
    nouser = sub(r'@([^\s]+)', '@USUARIO',chunk.lower())            #cambiar los ususarios por un placeholder
    nourl = sub(r'http[s]?://([^\s]+)', 'URL', nouser)      #igualmente para las URL's
    nolocale = sub(r'es\n', '\n', nourl, 0, Multiline)      #quitar el es del final de linea
    noredundancy = sub(r'((\D)\2{2,})', r'\1_\1', nolocale) #poner un guion
    return noredundancy

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
            tokens+=tknzr.tokenize(clean_and_tokenize(chunk))
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


index = index_big_file(input_file="solo_espanol.txt",chunk_size_mb=1)
