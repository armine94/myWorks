def printPascal(n):
    for line in range(0, n):
        for p in range(0, n - line):
            print(" ", end = "")
        for i in range(0, line + 1):
            res = 1
            pn = i
            if(pn > line - i):
                pn = line - i
            for j in range(0, pn):
                res = res * (line - j)
                res = res // (j + 1)
            print(res, " ",  end = "")

        print()

def main():
    number = int(input("Enter number greater than 0: "))
    if(number > 0):
        printPascal(number)
    else:
        print("Incorrect number")

if __name__ == "__main__":
    main()
