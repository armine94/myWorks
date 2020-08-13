#include <iostream>

void diff(const std::string str1, const std::string str2);
void entering(std::string &oldStr, std::string &newStr);

int main() {
    std::string oldStr;
    std::string newStr;

    //initialize data
    entering(oldStr, newStr);

    //checking difference oldStr and newStr
    diff(oldStr, newStr);

    return 0;
}


void entering(std::string &oldStr, std::string &newStr) {
    std::cout << "Enter Old string: ";
    std::cin >> oldStr;
    std::cout << "Enter New string: ";
    std::cin >> newStr;
}


void diff(const std::string str1, const std::string str2) {
    std::string str = "";//difference string

    if(str1 == str2) {
        std::cout<< "Not Difference: " << std::endl;
    }

    int i = 0; //current index for string1
    int j = 0; //current index for string2

    while (j < str1.size() && i < str2.size()) {
        if(str1[j] == str2[i]) {
            //not changed characters
            str += str1[j];
            ++j;
            ++i;
        } else {
            //find current element string1 in string2
            int index = str2.find(str1[j], i);

            //if the index is -1, then the character is not found
            if(index != -1) {
                for(int pos = i; pos < index; ++pos) {
                    //added characters before index
                    str = str + "+" + str2[i++];
                }
            } else {
                //deleted characters
                str = str + "-" + str1[j++];
            }
        }
    }

    //if  are  not  added characters, add its
    while (i < str2.size()) {
        str = str + "+" + str2[i++];
    }

    //if  are  deleted  characters, delete  its
    while (j < str1.size()) {
        str = str + "-" + str1[j++];
    }

    std::cout << "Difference: " << str << std::endl;
}