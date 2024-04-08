from cs50 import get_string


def readability(message):
    char = 0
    index = 0
    letter = 0
    word = 1
    sentences = 0
    for char in message:
        index += 1
        if char.isalpha():
            letter += 1
        elif char.isspace():
            word += 1
        elif char == "." or char == "!" or char == "?":
            sentences += 1
    averageWords = (100 / word) * letter
    averageSentences = (100 / word) * sentences
    index = round(0.0588 * averageWords - 0.296 * averageSentences - 15.8)
    if index < 1:
        print("Before Grade 1")
    elif index > 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


message = get_string("Text: ")
readability(message)
