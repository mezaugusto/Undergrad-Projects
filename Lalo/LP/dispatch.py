class A(object):
    def __init__(self):
        pass

    def f(self, a):
        return a


class B:
    def __init__(self):
        pass

    def f(self, a, b):
        return a / b


class C:
    def __init__(self):
        pass

    def f(self, a, b, c):
        return a * b * c


class D(A, B, C):
    def __init__(self):
        A.__init__(self)
        B.__init__(self)
        C.__init__(self)

instance = D()
print(A.f(instance, 1))
print(B.f(instance, 1, 2))
print(C.f(instance, 1, 2, 3))