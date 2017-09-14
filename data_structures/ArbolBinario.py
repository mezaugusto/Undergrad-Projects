
class Nodo(object):
    def __init__(self, dato):
        self.dato = dato
        self.izq = None
        self.der = None

    def __str__(self, modo):
        return str(self.dato)

    def cuentaHijos(self):
        hijos = 0
        if self.izq is not None:
            hijos += 1
        if self.der is not None:
            hijos += 1
        return hijos

class AB(object):
    def __init__(self, dato=None):
        self.raiz = Nodo(dato)

    def minimo(self, nodo, padre):
        if nodo is None:
            return nodo, padre
        elif nodo.izq is not None:
            return self.minimo(nodo.izq, nodo)
        return nodo, padre

    def maximo(self, nodo, padre):
        if not nodo.izq.isEmpty():
            return self.maximo(nodo.der, nodo)
        return nodo, padre

    def isEmpty(self):
        return self.raiz.dato is None

    #inserta en el arbol cada numero que se le mando a la funcion
    def insertar(self, *args):
        for x in args:
            self.insertarNodo(self.raiz,x)

    def insertarNodo(self,nodo,x):
        if nodo is None or nodo.dato is None:
                nodo.dato = x
        elif x < nodo.dato:
            if nodo.izq is not None:
                self.insertarNodo(nodo.izq, x)
            else:
                nodo.izq = Nodo(x)
        elif x > nodo.dato:
            if nodo.der is not None:
                self.insertarNodo(nodo.der, x)
            else:
                nodo.der = Nodo(x)
        else:
            return False
        return True

    def buscar(self, nodo, x, padre=None):
        if nodo is None or self.isEmpty():
            return None, None
        elif x < nodo.dato:
            return self.buscar(nodo.izq, x, nodo)
        elif x > nodo.dato:
            return self.buscar(nodo.der, x, nodo)
        else:
            return nodo, padre

    def sacar(self, x):
        aux, padre = self.buscar(self.raiz, x)
        if aux is not None:
            hijos = aux.cuentaHijos()
            if hijos == 0:
                if aux is self.raiz: #Si solo hay un nodo y es la raiz borra el arbol
                    self.raiz.dato = None
                elif padre.izq == aux:
                    padre.izq = None
                else:
                    padre.der = None
            elif hijos == 1:
                if aux is self.raiz: #si el nodo a sacar es la raiz efectua el cambio directamente
                    if aux.izq is not None:
                        self.raiz = aux.izq
                    else:
                        self.raiz = aux.der
                elif padre.izq == aux:
                    if aux.izq is not None:
                        padre.izq = aux.izq
                    else:
                        padre.izq = aux.der
                else:
                    if aux.izq is not None:
                        padre.der = aux.izq
                    else:
                        padre.der = aux.der
            else:
                sucesor, padreS = self.minimo(aux.der, aux)
                aux.dato = sucesor.dato
                if padreS.izq == sucesor:
                    padreS.izq = sucesor.der
                else:
                    padreS.der = sucesor.der
            return True
        return False

    def preOrden(self, nodo):
        if self.isEmpty() or nodo is None:
            return None
        print(str(nodo.dato if nodo != self.raiz else self.raiz.dato)+' ',end="")
        self.preOrden(nodo.izq)
        self.preOrden(nodo.der)

    def inOrden(self, nodo):
        if self.isEmpty() or nodo is None:
            return None
        self.inOrden(nodo.izq)
        print(str(nodo.dato if nodo != self.raiz else self.raiz.dato)+' ',end="")
        self.inOrden(nodo.der)

    def postOrden(self, nodo):
        if self.isEmpty() or nodo is None:
            return None
        self.postOrden(nodo.izq)
        self.postOrden(nodo.der)
        print(str(nodo.dato if nodo != self.raiz else self.raiz.dato)+' ',end="")

arbol = AB(8)
arbol.insertar(3,1,6,4,7,10,13,14,14)
arbol.sacar(14)
arbol.preOrden(arbol.raiz)
print()
arbol.sacar(8)
arbol.inOrden(arbol.raiz)
print()
arbol.insertar(14)
arbol.postOrden(arbol.raiz)
print()
arbol2 = AB(8)
arbol2.insertar(7)
arbol2.sacar(8)
arbol2.preOrden(arbol2.raiz)