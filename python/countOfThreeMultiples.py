def countOfThreeMultiples(n):
    #multiples count
    count = 0
    
    for i in range(102, n + 1, 3):
        #separating number
        start = i // 100
        mid = (i // 10) % 10
        end = i % 10
        #check if repeated number 
        if(start != mid and start != end and mid != end):
            count = count + 1
    return count

def main():
    num = int(input("Enter number greater than 99 and less than 1000: "))
    if(num > 99 and num < 1000):
        print("Number of 3 multiples from 100 to ", num, ": ", countOfThreeMultiples(num))
    else:
        print("Incorrect number")

if __name__ =="__main__":
    main()
