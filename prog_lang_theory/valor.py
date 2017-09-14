from numpy import poly1d


def newpoly(head):
    polinomio = list(range(int(input(head+"\nCual es el grado de tu polinomio: "))+1))
    for exponente in polinomio[::-1]:
        polinomio[exponente] = float(input("Cual es el coeficiente del exponente("+str(exponente)+"): "))
    return poly1d(polinomio[::-1])

def valuar(polinomio):
    x = float(input("Valor de x donde desea valuar la funcion: "))
    print(str(polinomio)+" cuando x = "+str(x)+" es "+str(polinomio(x)))


def sumar(polinomio_1, polinomio_2):
    print(polinomio_1+polinomio_2)


def restar(polinomio_1, polinomio_2):
    print(polinomio_1-polinomio_2)


def iden(polinomio_1, polinomio_2):
    print(polinomio_1 == polinomio_2)


def opuesto(polinomio):
    print(polinomio*-1)


def multi(polinomio_1, polinomio_2):
    print(polinomio_1*polinomio_2)

while True:
    menu = {1: valuar, 2: sumar, 3: restar, 4: iden, 5: opuesto, 6: multi}
    op = int(
        input("\t\t\tOpciones\n"
              "\n\t1)Valuar un polinomio"
              "\n\t2)Sumar polinomios"
              "\n\t3)Restar polinomios"
              "\n\t4)Igualdad de polinomios"
              "\n\t5)Polinomio opuesto"
              "\n\t6)Muiliplicar polinomios"
              "\nIngrese el numero de la opcion seleccionada: "))
    if op == 1 or op == 5:
        menu[op](newpoly("\nPolinomio"))
    else:
        menu[op](newpoly("\nPolinomio 1"), newpoly("\nPolinomio 2"))
    if input("\n¿Desea regresar a las opciones?(s/n): ") != 's':
        break
