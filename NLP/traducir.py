

palabras = {
"0":"C0",
"1":"F9",
"2":"A4",
"3":"B0",
"4":"99",
"5":"92",
"6":"82",
"7":"F8",
"8":"80",
"9":"98",
"A":"88",
"B":"83",
"C":"C6",
"D":"A1",
"E":"86",
"F":"8E",
"G":"90",
"H":"89",
"I":"E6",
"J":"E1",
"K":"85",
"L":"C7",
"M":"C8",
"N":"AB",
"O":"C0",
"P":"8C",
"Q":"98",
"R":"AF",
"S":"92",
"T":"87",
"U":"E3",
"V":"C1",
"W":"E2",
"X":"8F",
"Y":"91",
"Z":"B6",
" ":"FF",
"-":"BF"
}

with open("data.txt") as f:
    with open("output.txt","w") as o:
        for line in f.readlines():
            print(''.join(palabras.get(k, k)+" " for k in line.upper()))
            o.write(''.join(palabras.get(k, k)+" " for k in line.upper()))