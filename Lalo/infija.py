def operacion(op1, op2, operador):
    if operador == '+':
        return op2+op1
    elif operador == '-':
        return op2-op1
    elif operador == '/':
        return op2/op1
    elif operador == '%':
        return op2%op1
    elif operador == '*':
        return op2*op1
    raise TypeError("El operando"+operador+" no existe")


def aritmetica(cadena):
    if cadena.replace("(","").replace(")","").isdigit():
        return int(cadena.replace("(","").replace(")",""))
    parentesis = 0
    operadores = []
    operandos = []
    for letter in cadena.replace("res", "%"):
        if letter == '(':
            parentesis += 1
        elif letter == ')':
            parentesis -= 1
            if parentesis < 0:
                raise TypeError("Expresion mal formada")
            operandos.append(operacion(operandos.pop(), operandos.pop(), operadores.pop()))
        elif letter.isdigit():
            operandos.append(int(letter))
        else:
            operadores.append(letter)
    return operandos.pop()


def booleana(cadena):
    if cadena == 'V':
        return True
    elif cadena == 'F':
        return False
    expresion = list(cadena.replace("<=","<"))
    if expresion.pop(0) != "(" or expresion.pop() != ")":
        raise TypeError("Expresion mal formada")
    letter = expresion.pop(0)
    if letter == '¬':
        return not booleana(''.join(expresion))
    subcadena = ''
    parentesis = 0
    while parentesis != 0 or len(subcadena) == 0:
        if letter == ")":
            parentesis += -1
        elif letter == "(":
            parentesis += 1
        subcadena += letter
        letter = expresion.pop(0)
    simbolo = letter
    subcadena2 = ''
    parentesis = 0
    letter = expresion.pop(0)
    while parentesis != 0 or len(subcadena2) == 0:
        if letter == ")":
            parentesis += -1
        elif letter == "(":
            parentesis += 1
        subcadena2 += letter
        letter = expresion.pop(0) if len(expresion)>0 else ''
    if simbolo == '=':
        return aritmetica(subcadena) == aritmetica(subcadena2)
    elif simbolo == '<':
        return aritmetica(subcadena) <= aritmetica(subcadena2)
    elif simbolo == '^':
        return booleana(subcadena) and booleana(subcadena2)
    elif simbolo == '|' or simbolo == '∨':
        return booleana(subcadena) or booleana(subcadena2)

print(booleana(input('Cadena: ').replace(" ", '')))
