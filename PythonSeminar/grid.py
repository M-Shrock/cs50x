def main():
    bricks = int(input("Enter wall size:"))

    for i in range(bricks):
        printRow(bricks)

def printRow(n):
    print("#" * n)

main()