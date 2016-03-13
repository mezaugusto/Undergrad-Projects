import math
class Numcom(object):
    def __init__(self,a,b):
        self.a = a
        self.b = b
        self.obtain_module_and_argument()
    def obtain_module_and_argument(self):
        self.modulo = math.sqrt(self.a**2 + self.b**2)
        if self.a == 0 or self.b == 0:
            if self.a == 0:
                if self.b>0:
                    self.angulo = 90
                elif self.b == 0:
                    self.angulo = 0
                else:
                    self.angulo = 270
            else:
                if self.a>0:
                    self.angulo = 0
                else:
                    self.angulo = 180
        else:
            alpha = math.degrees(math.atan(float(self.b)/float(self.a)))
            if self.a>0 and self.b>0:
                self.angulo = alpha
            elif self.a<0 and self.b>0:
                self.angulo = 180 + alpha
            elif self.a<0 and self.b<0:
                self.angulo = 180 + alpha
            else:
                self.angulo = 360 + alpha
    def bin_print(self):
        if self.b > 0:
            print('%.2f+%.2fi'%(self.a,self.b))
        else:
            print('%.2f%.2fi'%(self.a,self.b))
    def pol_print(self):
        print('%.2fcis(%.2f°)'%(self.modulo,self.angulo))
    def constr(self,msg):
        print(msg)
        self.a = float(input('Parte Real: '))
        self.b = float(input('Parte Compleja: '))
        self.obtain_module_and_argument()
def suma(n1,n2):
    return Numcom(n1.a + n2.a,n1.b + n2.b)
def multi(n1,n2):
    return Numcom(n1.a*n2.a - n1.b*n2.b,n1.a*n2.b + n1.b*n2.a)
def div(n1,n2):
    a = n1.a*n2.a + n1.b*n2.b
    a /= n2.modulo ** 2
    b = n1.b*n2.a - n1.a*n2.b
    b /= n2.modulo ** 2
    return Numcom(a,b)
def pwr(n,pwr):
    modulo = n.modulo ** int(pwr)
    angulo = math.radians(n.angulo) * int(pwr)
    a = modulo * math.cos(angulo)
    b = modulo * math.sin(angulo)
    return Numcom(a,b)
def menu():
    op_dic = {1:'Suma',2:'Resta',3:'Multiplicacion',4:'Division',5:'Potencia',6:'Modulo y Angulo'}
    n1 = Numcom(0,0)
    n2 = Numcom(0,0)
    print("\t\tMenu")
    for op in op_dic:
        print('%s.-'%(op) + op_dic[op])
    sl_op = input('¿Que operacion desea realizar? ')
    if sl_op == '1' or sl_op == '2' or sl_op == '3' or sl_op == '4':
        n1.constr('\tNumero 1')
        n2.constr('\tNumero 2')
        if sl_op == '1' or sl_op == '2':
            if sl_op == '2':
                n2.a *= -1
                n2.b *= -1
                result = suma(n1,n2)
            else:
                result = suma(n1, n2)
        elif sl_op == '3':
            result = multi(n1, n2)
        else:
            result = div(n1, n2)
        result.bin_print()    
    elif sl_op == '5':
        n1.constr('\tNumero')
        potencia = input('Potencia: ')
        result = pwr(n1,potencia)
        result.bin_print()
    elif sl_op == '6':
        n1.constr('\tNumero')
        n1.pol_print()
    else:
        print('Opcion no valida\n\n')
reintentar = True        
while reintentar == True:
    menu()
    ask_try_again = input('¿Desea intentar otra vez?(S/N) ')
    if  ask_try_again == 's' or ask_try_again == 'S':
        reintentar = True
    else:
        reintentar = False