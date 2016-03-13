import random
"""Crea una clase y le asigna los tres metodos de solucion para encontrar el minimo y el maximo"""
class MinMax(object):
    def __init__(self,lista):
        self.comp_metodo1 = 0
        self.comp_metodo2 = 0
        self.comp_metodo3 = 0
        self.lista = lista
        self.min = lista[0]
        self.max = lista[0]
        self.metodo1()
        self.min = lista[0]
        self.max = lista[0]
        self.metodo2()
        self.min = lista[0]
        self.max = lista[0]
        self.metodo3()
    def metodo1(self):
        for element in self.lista[1::]:
            self.comp_metodo1+=1
            if element > self.max:
                self.max = element
            self.comp_metodo1+=1
            if element < self.min:
                self.min = element
    def metodo2(self):
        for element in self.lista[1::]:
            self.comp_metodo2+=1
            if element > self.max:
                self.max = element
            elif element < self.min:
                self.comp_metodo2+=1
                self.min = element
            else:
                self.comp_metodo2+=1
    def metodo3(self):
        for i in range(1,len(self.lista),2):
            if i+2 > len(self.lista):
                self.comp_metodo3+=1
                if self.lista[i]>self.max:
                    self.max = self.lista[i]
                elif self.lista[i]<self.min:
                    self.comp_metodo3+=1
                    self.min = self.lista[i]
            else:
                self.comp_metodo3+=1
                if self.lista[i] > self.lista[i+1]:
                    aux = self.lista[i]
                    self.lista[i]= self.lista[i+1]
                    self.lista[i+1]=aux
                self.comp_metodo3+=1
                if self.lista[i]<self.min:
                    self.min = self.lista[i]
                self.comp_metodo3+=1
                if self.lista[i+1]>self.max:
                    self.max = self.lista[i+1]
"""Genera una tabla con las comparaciones obtenidas en listas de tamaño de 1 a 100"""
print("\nLength\tMin\tMax\tM1\tM2\tM3\n")
for i in range(1,101):
    lista = random.sample(range(100),i)
    metodos_minmax = MinMax(lista)
    print(str(i)+"\t"+str(metodos_minmax.min)+"\t"+str(metodos_minmax.max)+"\t"+str(metodos_minmax.comp_metodo1)+"\t"+str(metodos_minmax.comp_metodo2)+"\t"+str(metodos_minmax.comp_metodo3)+"\t")