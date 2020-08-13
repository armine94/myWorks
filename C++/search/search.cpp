#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include "function.cpp"
#include "sorting.cpp"
#include "data.cpp"

int main() {
    std::vector<int> array;
    std::vector<std::string> str;
    unsigned int flag = typeOfArray();
    const unsigned int size = getSize();

    std::cout << "Enter elements of array" << std::endl;
    if(flag == 1) {
        enterData(str, size);
    } else {
        enterData(array, size);
    }

    //string or number need search
    const unsigned int number = algorithmNumber(flag);

    std::cout << "Enter what do you want search: ";
    if(flag == 1) {
        std::string val;//searching element
        std::cin >> val;
        str = shellSort(str, size);
        print(str, size);

        std::cout << std::endl << "index of " << val << " : " << search(str, val, number, size) << std::endl;
    } else {
        const int searchNum = searchNumber();
        array = shellSort(array, size);
        print(array, size);

        if(number != 6) {
            std::cout << std::endl << "index of " << searchNum << " : " << search(array, searchNum, number, size) << std::endl;
        } else {
            std::cout  << std::endl << "index of " << searchNum << " : " << interpolationSearch(array, size, searchNum) << std::endl;
        }
    }

    return 0;
}