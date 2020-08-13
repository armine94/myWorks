#Function for nth fibonacci number
def fibonacci(n):
    if(n < 0):
        print("Incorrect number")

    elif(n == 0 or  n == 1):
        #first and secont fibonacci number is 1
        return 1

    return fibonacci(n-1) + fibonacci(n-2)

#define main function
def main():
    numFibo = int(input("Enter number greater than 0: "))
    print(numFibo, "th Fibonacci number is: ", fibonacci(numFibo))

if __name__ == '__main__':
    main()
