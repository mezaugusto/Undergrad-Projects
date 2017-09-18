from csv import reader
from collections import Counter,defaultdict
from numpy import zeros,multiply


class XCounter():
    lst = None
    len = 0
    toId = None
    freq = None
    fromId = None
    uniques = None

def voc():
    dict = defaultdict()
    dict.default_factory = lambda: len(dict)
    return dict

def get_ids(C,dict):
    yield [dict[w] for w in C]

def p_cond(x, cond, N, l=1):
    return (x+l) / (cond + l*N)

def POSt(frase,A,B,pi,obv2id,id2emi,types):
    frase = frase.lower().split()
    frase_len = len(frase)

    phi = list(range(frase_len))
    delta = list(range(frase_len))
    # init
    phi[0] = pi.argmax()
    delta[0] = pi.max()

    # ind
    for j, next_obv in enumerate(frase[1:]):
        p_wj_emi = A[phi[j]]
        p_wj_obv = B[:, obv2id[next_obv]] if next_obv in types else 1

        partial = multiply(p_wj_obv, p_wj_emi)
        phi[j + 1] = partial.argmax()
        delta[j + 1] = partial.max() * delta[j]

    for word, emi in zip(frase, phi):
        print(word, id2emi[emi])

def obtainFreqs(corpus):
    emi = XCounter()
    obv = XCounter()
    emi.lst = []
    obv.lst = []
    emi.freq = Counter()
    obv.freq = Counter()
    for pair in corpus:
        token, tag = pair
        obv.freq[token] += 1
        emi.freq[tag] += 1
        emi.lst.append(tag)
        obv.lst.append((token, tag))

    emi.toId = voc()
    list(get_ids(emi.lst, emi.toId))
    emi.len = len(emi.toId)
    emi.fromId = list(emi.toId.keys())

    obv.uniques = list(obv.freq)
    obv.toId = voc()
    list(get_ids(obv.uniques, obv.toId))
    obv.len = len(obv.toId)
    obv.fromId = list(obv.toId.keys())

    return obv,emi

def train(filename):
    corpus = list(reader(open(filename)))
    obv,emi = obtainFreqs(corpus)
    A = zeros((emi.len, emi.len))
    chains = Counter(zip(emi.lst, emi.lst[1:]))
    for x in emi.lst:
        for y in emi.lst:
            comb_freq = chains[(x, y)]
            A[emi.toId[y], emi.toId[x]] = p_cond(comb_freq, emi.freq[y], emi.len)

    chains = Counter(obv.lst)
    B = zeros((emi.len, obv.len))
    for emi_i in emi.lst:
        for obv_i in obv.uniques:
            comb_freq = chains[(obv_i, emi_i)]
            B[emi.toId[emi_i], obv.toId[obv_i]] = p_cond(comb_freq, obv.freq[obv_i], obv.len)

    pi = zeros(emi.len)
    first_emi = obv.lst[0][1]
    for emi_i in emi.lst:
        freq = 1 if emi_i == first_emi else 0
        pi[emi.toId[emi_i]] = p_cond(freq, 0, emi.len)

    return A,B,pi,obv,emi



A,B,pi,obv,emi = train("corpusHMM.csv")
phrases = []
phrases.append("El alcohol es dañino para el hígado")
phrases.append("La geometría de un espacio se determina por el producto interno")
phrases.append("El PLN es divertido")
for i, phrase in enumerate(phrases):
    print("---------------Frase",i+1,"------------------------------")
    POSt(phrase, A, B, pi, obv.toId, emi.fromId, obv.uniques)