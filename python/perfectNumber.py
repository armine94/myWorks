def perfectNumber(n):
    count = 0

    for i in range(1, n//2 + 1):
        if(n % i == 0):
            count = count + i

    if(count == n):
        return True
    return False

def main():
    num = int(input("Enter number: "))
    print(perfectNumber(num))

if __name__ == "__main__":
    main()
