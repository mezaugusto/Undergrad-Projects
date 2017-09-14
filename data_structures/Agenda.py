class Agenda:
    def __init__(self, path_index='C:\\Users\\Augusto\\Documents\\Python\\AyED\\src\\index.dat',
                 path_agenda='C:\\Users\\Augusto\\Documents\\Python\\AyED\\src\\agenda.dat',
                 reg_size=40):
        self.path_index = path_index
        self.path_agenda = path_agenda
        self.reg_size = reg_size
        self.indice = []
        self.empty = []
        self.leer()
        print("\'Exito\'")

    def busqueda_binaria(self, x):
        if len(self.indice) == 0:
            return None
        left = 0
        right = len(self.indice)-1
        i = (left+right)//2
        while right > left and x != self.indice[i][0]:
            if x > self.indice[i][0]:
                left = i+1
            else:
                right = i-1
            i = (left+right)//2
        return i if self.indice[i][0] == x else None

    def leer(self):
        self.indice = []
        self.empty = []
        with open(self.path_index, "r") as file:
            for entry in file:
                if entry.split()[0] == 'unused':
                    for element in entry.split()[1:]:
                        self.empty.append(int(element))
                else:
                    self.indice.append(entry.replace('\n', '').split("      \t", 1))
        return "Exito"

    def buscar(self, name):
        contact_line = self.search_line_number(name)
        with open(self.path_agenda) as agenda:
            agenda.seek((self.reg_size+2)*contact_line)
            data = agenda.read(self.reg_size+1)
        return data.replace('\n', '').replace(':', '')

    def guardar(self):
        if len(self.indice) == 0:
            raise Exception("Nada para guardar")
        with open(self.path_index, "w") as file:
            for item in self.indice:
                file.write(item[0]+'      \t'+item[1]+'\n')
            file.write('unused\t')
            for item in self.empty:
                file.write(str(item)+' ')
        return "Exito"

    def string_set_size(self, name='', number=''):
        while len(name+number) < self.reg_size:
            name += ' '
        return name+number

    def add(self, name, number):
        if self.busqueda_binaria(name) is not None or name == 'unused':
            raise Exception("El nombre ya existe o esta reservado(\'unused\')")
        name += ':'
        if len(name+number) > self.reg_size:
            raise Exception("Se excedio el numero de caracteres maximo: "+str(self.reg_size))
        if len(self.empty) > 0:
            contact_line = self.empty.pop()
            with open(self.path_agenda, "r+") as agenda:
                agenda.seek((self.reg_size+2)*contact_line)
                agenda.write(self.string_set_size(name, number)+'\n')
            contact_line += 1
        else:
            with open(self.path_agenda, "a") as agenda:
                agenda.write(self.string_set_size(name, number)+'\n')
            contact_line = len(self.indice)+1
        self.indice.append([name.replace(':', ''), str(contact_line)])
        self.indice.sort()
        return "Exito"

    def search_line_number(self, name):
        contact_line = self.busqueda_binaria(name)
        if contact_line is None:
            raise Exception("El nombre no existe")
        return int(self.indice[contact_line][1])-1

    def delete(self, name):
        contact_line = self.search_line_number(name)
        with open(self.path_agenda, "r+") as agenda:
                agenda.seek((self.reg_size+2)*contact_line)
                agenda.write(self.string_set_size())
        self.indice.remove([name, str(contact_line+1)])
        self.empty.append(contact_line)
        return "Exito"

    def clean(self):
        open(self.path_agenda, 'w').close()
        open(self.path_index, 'w').close()
        self.leer()
        print("\'Exito\'")

a = Agenda()