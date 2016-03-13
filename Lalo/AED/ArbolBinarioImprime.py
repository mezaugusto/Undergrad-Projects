from graphviz import Digraph


class Nodo(object):
    def __init__(self, dato):
        self.dato = dato
        self.izq = None
        self.der = None
        self.numeroNodo = '0'

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
        self.grafica = None
        self.raiz = Nodo(dato)
        self.numeroNodos = 1

    def renderNode(self, nodo):
        if nodo is None:
            return None
        if nodo.izq is not None:
            self.numeroNodos += 1
            nodo.izq.numeroNodo = str(self.numeroNodos)
            self.grafica.node(nodo.izq.numeroNodo, label=str(nodo.izq.dato))
            self.grafica.edge(nodo.numeroNodo, nodo.izq.numeroNodo, label="I")
            self.renderNode(nodo.izq)
        if nodo.der is not None:
            self.numeroNodos += 1
            nodo.der.numeroNodo = str(self.numeroNodos)
            self.grafica.node(nodo.der.numeroNodo, label=str(nodo.der.dato))
            self.grafica.edge(nodo.numeroNodo, nodo.der.numeroNodo, label="D")
            self.renderNode(nodo.der)

    def render(self):
        self.grafica = Digraph(comment="Arbol Binario de Busqueda", format="png")
        if self.isEmpty():
            self.grafica.render(view=True)
            return False
        self.raiz.numeroNodo = str(self.numeroNodos)
        self.grafica.node(self.raiz.numeroNodo, label=str(self.raiz.dato))
        self.renderNode(self.raiz)
        self.grafica.render(view=True)

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

    def insertar(self, *args):
        for x in args:
            self.insertarNodo(self.raiz, x)
        self.render()

    def insertarNodo(self, nodo, x):
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
            self.render()
            return True
        return False

    def preOrden(self, nodo):
        if self.isEmpty() or nodo is None:
            return None
        print(str(nodo.dato if nodo != self.raiz else self.raiz.dato) + ' ', end="")
        self.preOrden(nodo.izq)
        self.preOrden(nodo.der)

    def inOrden(self, nodo):
        if self.isEmpty() or nodo is None:
            return None
        self.inOrden(nodo.izq)
        print(str(nodo.dato if nodo != self.raiz else self.raiz.dato) + ' ', end="")
        self.inOrden(nodo.der)

    def postOrden(self, nodo):
        if self.isEmpty() or nodo is None:
            return None
        self.postOrden(nodo.izq)
        self.postOrden(nodo.der)
        print(str(nodo.dato if nodo != self.raiz else self.raiz.dato) + ' ', end="")
