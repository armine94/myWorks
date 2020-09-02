#include <iostream>
#include <vector>


std::vector<int> vec = {0, 1};
void entering(int&);
int recFibo(int);
int fibo(int);

int main() {
    int size;

    entering(size);
    std::cout << size << "th fibo = " << recFibo(size - 1) << std::endl;

    entering(size);
    std::cout << size << "th fibo = " << recFibo(size - 1) << std::endl;

    entering(size);
    std::cout << size << "th fibo = " << fibo(size) << std::endl;

    entering(size);
    std::cout << size << "th fibo = " << fibo(size) << std::endl;

    return 0;
}


void entering(int &size) {
    std::cout << "enter size: ";
    std::cin >> size;
    while (size < 1) {
        std::cout << "Enter number greather 0: ";
        std::cin >> size;
    }
}


int recFibo(int n) {
    if(n < vec.size()) {
        return vec[n];
    } else {
        int tmp = recFibo(n-1) + recFibo(n-2);
        vec.push_back(tmp);
        return tmp;
    }
}


int fibo(int size) {
    if(vec.size() == 0) {
        for(int i = 0; i < size; ++i) {
            if(i == 0 || i == 1) {
                vec.push_back(i);
            } else {
                vec.push_back(vec[i - 1] + vec[i - 2]);
            }
        }
    } else if(size > vec.size()) {
        if(vec.size() == 1) {
            vec.push_back(1);
        }

        for(int i = vec.size(); i < size; ++i) {
            vec.push_back(vec[i - 1] + vec[i - 2]);
        }
    }

    return vec[size - 1];
}