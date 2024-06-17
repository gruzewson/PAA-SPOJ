from fractions import Fraction

def parsuj_wyrazenie(wyrazenie):
    elementy = []
    element = ""
    for znak in wyrazenie:
        if znak.isalnum():
            element += znak
        else:
            if element:  # Jeśli element nie jest pusty
                elementy.append(element)
                element = ""
            if znak != '_' and znak != ' ':
                elementy.append(znak)
    if element:
        elementy.append(element)
    return elementy

def onp(wyrazenie, rownania):
    stos = []
    for i in range(len(wyrazenie)):
        if wyrazenie[i].isnumeric():
            stos.append(wyrazenie[i])
        elif wyrazenie[i].isalpha():
            for j in rownania.keys():
                if j == wyrazenie[i]:
                    stos.append(rownania[j])
        elif len(stos) != 0:
            if wyrazenie[i] == '*':
                x = stos.pop()
                y = stos.pop()
                stos.append(x * y)
            elif wyrazenie[i] == '/':
                x = stos.pop()
                y = stos.pop()
                if(x != 0):
                    stos.append(y / x)
                else:
                    #print("whaaat", wyrazenie)
                    return "zero"
            elif wyrazenie[i] == '+':
                x = stos.pop()
                y = stos.pop()
                stos.append(x + y)
    return stos.pop()



def main():
    rownania = {}
    i = -1
    zero = 0
    while True:
        try:
            i += 1
            rownanie = ""
            while "case" not in rownanie:
                rownanie = input()
                if '=' in rownanie:
                    zmienna, wyrazenie = rownanie.split('=')
                    wyrazenie = parsuj_wyrazenie(wyrazenie)
                    rownania[zmienna] = wyrazenie
                else:
                    break

            x = 1
            for k in reversed(rownania.keys()):
                if x == 1:
                    #print(rownania[k][2])
                    if(int(rownania[k][2]) != 0):
                        rownania[k] = Fraction(int(rownania[k][0]), int(rownania[k][2]))
                    else:
                        print("case", i, "N")
                        zero = 1
                        break
                        #print("ulamek zero")
                    x += 1
                else:
                    rownania[k] = onp(rownania[k], rownania)
                    if(rownania[k] == "zero"):
                        print("case", i, "N")
                        zero = 1
            if(zero == 0 and i >= 1):
                print("case", i, "Y")
                for zmienna, wyrazenie in sorted(rownania.items()):
                    ulamek = Fraction(wyrazenie)
                    print(f"{zmienna} {ulamek.numerator} {ulamek.denominator}")
            rownania = {}
            zero = 0
        except EOFError:
            x = 1
            for k in reversed(rownania.keys()):
                if x == 1:
                    # print(rownania[k][2])
                    if (int(rownania[k][2]) != 0):
                        rownania[k] = Fraction(int(rownania[k][0]), int(rownania[k][2]))
                    else:
                        print("case", i, "N")
                        zero = 1
                        break
                        # print("ulamek zero")
                    x += 1
                else:
                    rownania[k] = onp(rownania[k], rownania)
                    if (rownania[k] == "zero"):
                        # print("rownania == 0")
                        print("case", i, "N")
                        zero = 1
                        break
            if (zero == 0 and i >= 1):
                print("case", i, "Y")
                for zmienna, wyrazenie in sorted(rownania.items()):
                    ulamek = Fraction(wyrazenie)
                    print(f"{zmienna} {ulamek.numerator} {ulamek.denominator}")
            return 0

main()
