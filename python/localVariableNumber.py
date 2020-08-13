def my_function():
    var = 1         #first variable
    str = "Python"  #second variable
    ITC = "ITC11"   #third variable

def main():
    #number of local variable in function my_function 
    print(my_function.__code__.co_nlocals)

if __name__ == "__main__":
    main()
