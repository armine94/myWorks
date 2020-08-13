#include <iostream>
#include <vector>
#include <algorithm>

int getUglyNum(std::vector<int> &vec, int n) {
    static int i2 = 0;
    static int i3 = 0;
    static int i5 = 0;

    int next2mul = vec[i2] * 2;
    int next3mul = vec[i3] * 3;
    int next5mul = vec[i5] * 5;
    int next ;

    for(int i = vec.size(); i < n; ++i) {
        next = std::min(std::min(next2mul, next3mul), next5mul); //find next ugly number
        vec.push_back(next);

        if (next == next2mul) {
            ++i2; //increase iterator of ugly numbers whose factor is 2
            next2mul = vec[i2] * 2;
        }

        if (next == next3mul) {
            ++i3; //increase iterator of ugly numbers whose factor is 3
            next3mul = vec[i3] * 3;
        }

        if (next == next5mul) {
            ++i5; //increase iterator of ugly numbers whose factor is 5
            next5mul = vec[i5] * 5;
        }
    }

    return vec[n - 1]; //the nth ugly number
}


void entering(int &size) {
    std::cout << "Enter number: ";
    std::cin >> size;
    while (size < 1) {
        std::cout << "Enter number greather 0: ";
        std::cin >> size;
    }
}


int main() {
    std::vector<int> vec;
    vec.push_back(1);
    int n;

    entering(n);
    std::cout << getUglyNum(vec, n) << std::endl;

    entering(n);
    std::cout << getUglyNum(vec, n) << std::endl;


    entering(n);
    std::cout << getUglyNum(vec, n) << std::endl;
    return 0;
}