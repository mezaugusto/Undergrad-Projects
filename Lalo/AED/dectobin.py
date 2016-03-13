class DecToBin(object):
    def __init__(self,dec,bits):
        self.dec = dec
        self.bits = bits
        self.dectobin()
    def dectobin(self):
        backup = int(self.dec)
        self.bin = ''
        if int(backup)<0:
            signo = '1'
            backup*=-1
        else:
            signo = '0'
        if backup > pow(2,int(self.bits)-1) - 1:
            print('El numero de bytes no alcanza para representar el numero')
            quit()
        while backup >= 1:
            if backup%2 == 0:
                self.bin += '0'
                backup /= 2
            else:
                self.bin += '1'
                backup=(backup-1) / 2
        while len(self.bin)+len(signo) != int(self.bits):
            signo += '0'
        self.bin = signo + self.bin[::-1]
        self.obtain_c1()
        self.obtain_c2()
    def obtain_c1(self):
        if self.bin[0] == '1':
            self.c1 = self.bin[0]
            for letter in self.bin[1::]:
                if letter == '0':
                    self.c1 += '1'
                else:
                    self.c1 += '0'
        else:
            self.c1 = self.bin
    def obtain_c2(self):
        if self.bin[0] == '1':
            self.c2 = self.bin[0]
            primer_uno = False
            backup = ''
            for letter in self.bin[:0:-1]:
                if letter == '1' and primer_uno:
                    backup += '0'
                elif letter == '1' and not primer_uno:
                    backup += '1'
                    primer_uno = True
                elif letter == '0' and primer_uno:
                    backup += '1'
                else:
                    backup += '0'
            for letter in backup[::-1]:
                self.c2 += letter
        else:
            self.c2 = self.bin
try:
    n = DecToBin(input('Ingrese el numero en decimal: '),input('Ingrese la cantidad de bits: '))
    print('Signo y Magnitud:\t'+n.bin)
    print('Complemento a 1:\t'+n.c1)
    print('Complemento a 2:\t'+n.c2)
except ValueError:
    print('El valor ingresado no es un numero, reinicie el programa')