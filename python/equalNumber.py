def boolFunction(num):
    #if number greater or less 1000/2000 of 100 return True else False 
    return (abs(1000 - num) == 100 or abs(2000 - num) == 100)

def main():
    num = int(input("Enter number: "))
    print(boolFunction(num))

if __name__ == "__main__":
    main()
