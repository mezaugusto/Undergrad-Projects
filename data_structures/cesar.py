def cesarmove(phrase,clave,decrypting):
    moved_phrase=''
    if decrypting:
        clave *= -1
    while clave > 25:
        if not decrypting:
            clave += -25
        else:
            clave += -26
    while clave < 0:
        clave += 26
    for letter in phrase:
        if letter != ' ':
            if ord(letter)+clave>ord('Z'):
                moved_phrase += chr(ord(letter)+clave-ord('Z')+ord('A')-1)
            else:
                moved_phrase += chr(ord(letter)+clave)
    return moved_phrase
encrypted_word = cesarmove( input('Frase a Encriptar: ').upper(), int(input('Clave: ')), False)
print(encrypted_word)
decrypted_word = cesarmove( input('Frase a Desencriptar: ').upper(), int(input('Clave: ')), True)
print(decrypted_word)