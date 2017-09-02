from numpy import matrix,array_equal

with open("2prueba1.txt") as f:
    for line in f.readlines():
        m = matrix(line)
        mtrans = m.transpose()
        if array_equal(m,mtrans):
            print('Symmetric')
        else:
            print('Not symmetric')