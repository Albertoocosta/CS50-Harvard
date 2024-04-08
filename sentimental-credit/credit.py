from cs50 import get_int


def checkBank(nbr):
    while nbr > 99:
        nbr = nbr // 10
    return nbr


def countDigits(nbr):
    i = 0
    while nbr != 0:
        nbr //= 10
        i += 1
    return i


def checkNumber(nbr):
    i = 1
    soma = 0
    check = nbr
    digit = 0
    while check != 0:
        digit = check % 10
        if i % 2 == 0:
            digit *= 2
            soma += (digit // 10) + (digit % 10)
        else:
            soma += digit
        check //= 10
        i += 1
    if soma % 10 == 0:
        if (checkBank(nbr) == 34 or checkBank(nbr) == 37) and countDigits(nbr) == 15:
            print("AMEX")
        elif (checkBank(nbr) == 51 or checkBank(nbr) == 52 or checkBank(nbr) == 53 or checkBank(nbr) == 54 or checkBank(nbr) == 55) and countDigits(nbr) == 16:
            print("MASTERCARD")
        elif (checkBank(nbr) // 10) == 4 and (countDigits(nbr) == 13 or countDigits(nbr) == 16):
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")


nbr = get_int("Number: ")
checkNumber(nbr)
