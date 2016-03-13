def encryptor(frase, columnas, modo):  # frase(string sin espacios convertido a lista),clave y modo(enteros)
    filas = int(len(frase)/columnas)  # Division entera de la frase entre la clave (o numero de columnas que se quieren)
    filas += 1 if filas*columnas < len(frase) else 0  # Si faltan espacios en la matriz aumentamos una fila
    (filas, columnas) = (columnas, filas) if modo == 2 else (filas, columnas)  # Para desencriptar transponer la matriz
    resultado = [[i+x for i in range(columnas)] for x in range(filas)]  # Crear la matriz de [i=filas][j=columnas]
    for i, list_fila in enumerate(resultado):  # Iterar por toda la matriz
        for j, list_columna in enumerate(resultado[i]):
            resultado[i][j] = frase.pop(0) if len(frase) > 0 else 'N'  # Guardar el primer elemento de la frase
    string = '' # String vacio donde guardaremos el resultado
    for j in range(columnas):  # Iteramos la matriz primero por columnas y luego por filas
        string += ''.join(resultado[i][j] for i in range(filas))  # De cada columna guardamos las letras de todas sus filas
    return string

print(encryptor(list(input("Frase: ").replace(" ", "")), int(input("Clave: ")), int(input("Encriptar(1) o Desencriptar(2): "))))