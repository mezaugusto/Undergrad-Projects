from math import sqrt, atan2, degrees


def invertir_lista(lista):
    return lista[::-1]


def distancias_y_angulos(lista):
    res = []
    for i, punto in enumerate(lista):
        if len(lista) > i+1:
            dx = lista[i+1][0]-punto[0]
            dy = lista[i+1][1]-punto[1]
            distancia = sqrt(dx**2+dy**2)
            angulo = degrees(atan2(dy, dx))
            res.insert(i, (round(distancia, 4), round(angulo, 4)))
    return res


def parseo(delimitador, cadena):
    cadena = cadena.replace("]", "").replace("[", "").replace(" ", "")
    cadena = cadena.split(delimitador)
    if delimitador == ",":
        return [int(x) for x in cadena]
    res = []
    for item in cadena:
        item = item.replace("(", "").replace(")", "")
        item = list(item.replace(",", ""))
        res.insert(0, tuple(int(x) for x in item))
    return res[::-1]

if input("\tMenu\n1)Invertir una lista\n2)Distancia y Angulo entre dos pares de puntos\nSeleccione un numero: ") == '1':
    print(invertir_lista(parseo(",", input("Ingrese la lista a invertir:"))))
else:
    print(distancias_y_angulos(parseo("),(", input("Ingrese la lista de pares de puntos:"))))

"""
print(distancias_y_angulos([(0, 0), (1, 1), (2, 1), (2, 2), (3, 4), (1, 1)]))
print(parseo("),(","[(0, 0), (1, 1), (2, 1), (2, 2), (3, 4), (1, 1)]"))
print(parseo(",","[1]"))
"""