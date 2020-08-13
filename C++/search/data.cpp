//======================================================================
//=                        Enter data in vector                        =
//======================================================================

template <typename T>
void enterData(std::vector<T> &arr, const unsigned int size) {
    T tmp;
    for(int i = 0; i < size; ++i) {
        std::cout << "array[" << i << "]: ";
        std::cin >> tmp;
        arr.push_back(tmp);
    }
}

//======================================================================
//=                         get size for vector                        =
//======================================================================
unsigned int getSize() {
    std::cout << "Enter size of array: ";
        std::string number;
    std::cin >> number;
    int i = 0;
    bool flag = true;

    while (flag == true) {
        while ((number[i] > '0' && number[i] <= '9' ) || number[i] =='.' && i < number.size()) {
            i++;
        }
        if (i == number.size()) {
            flag = false;
        } else {
            std::cout << "Please enter number greater of 0: ";
            std::cin >> number;
        }
    }

    return stoi(number);
}


//======================================================================
//=                   vector type string or integer                    =
//======================================================================

unsigned int typeOfArray() {
    std::cout << "Do you wont create array of string or number?\nfor string enter 1, for number enter 2: ";
    char flag[] = "";
    std::cin >> flag;

    //check flag
    while (atoi(flag) <= 0 || atoi(flag) > 2) {
        std::cout << "Please enter 1 for array of string or 2 for array of number: ";
        std::cin >> flag;
    }

    return atoi(flag);
}


//======================================================================
//=                         which algorithm need used                  =
//======================================================================

unsigned int algorithmNumber(unsigned int flag) {
    std::cout << "Which is sorting algorithm do you want use ? " << std::endl;
    std::cout << "For Liner search enter 1, for Binary search enter 2, for Jump search enter 3, for Exponential search 4, for Ternary search 5";
    if(flag == 2) {
        std::cout << ", for Interpolation search 6";
    }
    std::cout << " : ";
    char number[] = "";
    std::cin >> number;

    while (atoi(number) <= 0 || atoi(number) > 6) {
        std::cout << "Please enter: 1 for Liner search, 2 for Binary search, 3 for Jump search, 4 for Exponential search, 5 for Ternary search";
        if(flag == 2) {
            std::cout << ", 6 for Interpolation search";
        }
        std::cout << " : ";
        std::cin >> number;
    }

    return atoi(number);
}


//======================================================================
//=                         call searching algorithm                    =
//======================================================================

template <typename T>
int search(std::vector<T> vec, const T value, const unsigned int algorithm, const unsigned int size) {
    switch (algorithm)
    {
    case 1:
        return linerSearch(vec, size, value);
        break;

    case 2:
        return binarySearch(vec, size, value);
        break;

    case 3:
        return jumpSearch(vec, size, value);
        break;

    case 4:
        return exponentialSearch(vec, size, value);
        break;

    case 5:
        return ternarySearch(vec, 0, size, value);
        break;

    default:
        break;
    }

}


//======================================================================
//=                     get number which need search                   =
//======================================================================

int searchNumber() {
    std::string number;
    std::cin >> number;
    int i = 0;
    bool flag = true;

    while (flag == true) {
        while ((number[i] >= '0' && number[i] <= '9' )  && i < number.size()) {
            i++;
        }

        if (i == number.size()) {
            flag = false;
        } else {
            std::cout << "Please enter only number: ";
            std::cin >> number;
        }
    }

    return stoi(number);
}