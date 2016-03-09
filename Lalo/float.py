"""
This example module shows various types of documentation available for use
with pydoc.  To generate HTML documentation for this module issue the
command:

    pydoc -w foo

"""

def enterotobin(numero):
    return bin(numero)[2::] if numero>0 else bin(numero)[3::]


def decimaltobin(numero):
    res=[]
    while len(res) < 23:
        numero *= 2
        if numero >= 1:
            res.append('1')
            numero += -1
        else:
            res.append('0')
    return ''.join(res)


def synth(res):
    res = res.split('.')
    entera = int(res[0])
    signo = '1' if entera<0 else '0'
    decimal = float('0.'+res[1])
    return enterotobin(entera), decimaltobin(decimal),signo


def normalize(res):
    return len(synth(res)[0])-1


def simplefloat(cadena):
    exponente=bin(normalize(cadena)+127)[2::]
    entera, decimal, signo = synth(cadena)
    return signo+exponente+(entera[1::]+decimal)[:23:]


def sumadecimal(cadena):
    exp = -1
    suma = 0
    cadena = list(cadena[::-1])
    while len(cadena) > 0:
        suma += int(cadena.pop())*(2**exp)
        exp += -1
    return suma


def floattodec(cadena):
    signo = -1 if cadena[0]=='1' else 1
    exponente=int(cadena[1:9:], 2)-127
    mantisa = sumadecimal(cadena[9::])+1
    return str(signo*(2**exponente)*mantisa)

menu = {'1': simplefloat, '2': floattodec}
print('Res: '+menu[input('\n\t\tIEEE 754 Float\n1)Decimal a Binario\n2)Binario a Decimal\nOpcion: ')](input('Entrada: ')))
