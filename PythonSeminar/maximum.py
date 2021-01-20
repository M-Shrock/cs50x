def main():
    x = int(input("x: "))
    y = int(input("y: "))
    print("Maximum is", maximum(x, y))

def maximum(a, b):
    if a > b:
        return a
    else:
        return b

main()