
# TODO: Leer los documentos y tokenizar, indizar,
from re import sub,M as Multiline
from nltk import word_tokenize
from sys import  stdout
from pprint import pprint

debug = False

def file_len(fname,encoding):
    with open(fname,encoding=encoding) as f:
        for i, l in enumerate(f):
            pass
    return i + 1

def clean_and_tokenize(chunk):
    lowered = chunk.lower()
    nouser = sub(r'@([^\s]+)', '@USUARIO', lowered)
    nourl = sub(r'http[s]?://([^\s]+)', 'URL', nouser)
    nolocale = sub(r'es\n', '\n', nourl, 0, Multiline)
    separate = sub(r'([\W\d_]+)', r' \1 ', nolocale)
    noredundancy = sub(r'(\D)\1+', r'\1_\1', separate)
    return word_tokenize(noredundancy)

def update_progress(progress):
    stdout.write('\rProcesando archivo {:2.2f}%'.format(progress))

def tokenize_big_file(relative_path,encoding):
    tokens = []
    step = 100/file_len(relative_path,encoding)
    with open(relative_path, encoding=encoding) as corpus:
        for i,line in enumerate(corpus):
            tokens+=clean_and_tokenize(line)
            current_progress = step*i
            if current_progress > 5 and debug:
                break
            update_progress(current_progress)
    update_progress(100)
    return tokens


tokens = tokenize_big_file("solo_espanol.txt","utf-8")

with open("tokens.txt",'w',encoding='utf-8') as f:
    types = sorted(set(tokens))
    number_of_types = range(len(types))
    index = dict(zip(number_of_types,types))
    pprint(index,stream=f)
