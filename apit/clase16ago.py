
# TODO: Leer los documentos y tokenizar, indizar,
from re import sub,M as Multiline
from nltk import word_tokenize
from sys import  stdout
from os import stat

def clean_and_tokenize(chunk):
    lowered = chunk.lower()
    nouser = sub(r'@([^\s]+)', '@usuario', lowered)
    nourl = sub(r'http[s]?://([^\s]+)', 'URL', nouser)
    nolocale = sub(r'es\n', '\n', nourl, 0, Multiline)
    return word_tokenize(nolocale)

def update_progress(progress):
    stdout.write('\rProcesando archivo {:2.2f}%'.format(progress))

def tokenize_big_file(relative_path,encoding,chunk_size):
    tokens = []
    step = 100 / (stat(relative_path).st_size / chunk_size)
    current_progress = 0
    with open(relative_path, encoding=encoding) as corpus:
        for chunk in iter((lambda: corpus.read(chunk_size)), ''):
            tokens+=clean_and_tokenize(chunk)
            current_progress+=step
            update_progress(current_progress)
    return tokens

chunk_size = 2   * 1000000
tokens = tokenize_big_file("solo_espanol.txt","utf-8",chunk_size)
print(set(tokens))
