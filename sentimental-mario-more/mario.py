from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break
for i in range(height):
    i += 1
    for space in range(height - i):
        space += 1
        print(" ", end="")
    for left in range(i):
        print("#", end="")
    print("  ", end="")
    for right in range(i):
        print("#", end="")
    print()
