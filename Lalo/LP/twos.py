def binwoformat(decimal):  # Devuelve el string del binario sin el prefijo
    return bin(decimal)[2::] if decimal > 0 else bin(decimal)[3::]  # Sí es negativo quita 3 caracteres si no 2


def twoscomp(decimal):  # Devuelve el string del complemento a 2 de un decimal
    auno = onecomp(decimal)  # Obtiene el string del complemento a 1
    res = binwoformat(int(auno, 2)+1)  # Le suma uno al complemento a 1
    while len(res) < len(auno):  # Para conservar la misma longitud se compara el resultado con el complemento a 1
        res = '0' + res  # Se agregan 0's a la izquierda para que el complemento a 2 sea correcto
    return res  # Regresa el string con el numero en complemento a 2


def onecomp(decimal):  # Devuelve el string del complemento a 1 de un decimal
    binario = binwoformat(decimal)  # Convierte el decimal a binario sin el prefijo
    res = []  # Lista donde se guardara el resultado
    for bit in binario[::-1]:  # Recorre el numero binario de der a izq
        res.insert(0, '0' if bit == '1' else '1')  # Niega los bits y efectua push con el bit a la lista res
    return ''.join(res)  # Regresa el string con el numero en complemento a 1


def dectotwos(decimal):  # Recibe un numero en decimal y devuelve su complemento a 2 y a 1
    if decimal < 0:  # si el decimal es negativo efectua complementos
        decimal *= -1  # convierte el numero a positivo
        return '1'+twoscomp(decimal), '1'+onecomp(decimal)  # Devuelve complementos con bit de signo 1
    return '0'+binwoformat(decimal), '0'+binwoformat(decimal)  # Decimal positivo devuelve binario con bit de signo 0


def bintodec(binario, modo):  # Recibe un numero en binario con su modo(Complemento a 1 o a 2)
    if binario[0] == "1":  # Si el bit de signo es 1 efectua las operaciones para numeros negativos
        binario = int(binario, 2)  # Convierte el string a representacion entera
        if modo == "2":  # Para el complemento a 2
            decimal = int(twoscomp(binario), 2)  # Obtiene el complemento a 2 y del resultado obtiene el decimal
            return '1'+onecomp(decimal), decimal*-1, "1"  # Regresa complemento a 1 del decimal(con signo) y decimal negativo
        decimal = int(onecomp(binario), 2)  # Si es complemento a 1 lo vuelve a aplicar y saca de ese valor el decimal
        return '1'+twoscomp(decimal), decimal*-1, "2"  # Regresa complemento a 2 del decimal(con signo) y decimal negativo
    return binario, int(binario, 2), "2" if modo == "1" else "2"  # Con bit de signo positivo devuelve las conversiones
# Pide los datos en funcion del modo
if input("\tModos\n1)Base 10 a C1 y C2\n2)Binario en C1 o C2 a base 10\nSeleccione un modo: ") == "1":
    print("Complemento a 1: {1}\nComplemento a 2: {0}".format(*dectotwos(int(input("Ingrese el decimal: ")))))
else:
    print("Decimal: {1}\nComplemento a {2}: {0}".format(*bintodec(input("Binario: "), input("C1(1) o C2(2): "))))
