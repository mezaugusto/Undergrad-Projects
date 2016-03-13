def operacion(op1, op2, operador):
    if operador == '+':
        return op2+op1
    elif operador == '-':
        return op2-op1
    elif operador == '/':
        return op2/op1
    elif operador == '%':
        return op2 % op1
    elif operador == '*':
        return op2*op1
    raise TypeError


def aritmetica(cadena):
    if cadena.replace("(", "").replace(")", "").isdigit():
        return int(cadena.replace("(", "").replace(")", ""))
    parentesis = 0
    operadores = []
    operandos = []
    for letter in cadena.replace("res", "%"):
        if letter == '(':
            parentesis += 1
        elif letter == ')':
            parentesis -= 1
            if parentesis < 0:
                raise TypeError
            operandos.append(operacion(operandos.pop(), operandos.pop(), operadores.pop()))
        elif letter.isdigit():
            operandos.append(int(letter))
        else:
            operadores.append(letter)
    return operandos.pop()


def agrupar(expresion, letter):
    subcadena = ''
    parentesis = 0
    while parentesis != 0 or len(subcadena) == 0:
        if letter == ")":
            parentesis += -1
        elif letter == "(":
            parentesis += 1
        subcadena += letter
        letter = expresion.pop(0) if len(expresion) > 0 else None
    return subcadena, letter


def booleana(cadena):
    expresion = list(cadena)
    if expresion.pop(0) != "(" or expresion.pop() != ")":
        raise TypeError
    letter = expresion.pop(0)
    if letter == '¬':
        return not booleana(''.join(expresion))
    subcadena, simbolo = agrupar(expresion, letter)
    subcadena2, letter = agrupar(expresion, expresion.pop(0))
    if simbolo == '=':
        return aritmetica(subcadena) == aritmetica(subcadena2)
    elif simbolo == '<':
        return aritmetica(subcadena) <= aritmetica(subcadena2)
    elif simbolo == '^':
        return booleana(subcadena) and booleana(subcadena2)
    elif simbolo == '|' or simbolo == '∨':
        return booleana(subcadena) or booleana(subcadena2)

try:
    print("Resultado: "+str(booleana(
            input('Expresion Booleana: ').replace(" ", '').replace("<=", "<").replace("V", "1").replace("F", "0"))))
except (TypeError, IndexError):
    print("Error: Expresion mal formada, verifique la expresion.")
