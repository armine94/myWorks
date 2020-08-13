#include "countOfPossibleWayBuilding.h"

std::vector<int> vec(1, 0);
std::vector<int> vecfibo = {0, 1};

unsigned int countB = 1;
unsigned int countS = 1;

//input and checking n
void entering(int &n) {
    std::cout << "Enter number for counting sections way: ";
    std::cin >> n;

    while (n < 0 || std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Please enter number greather 0: ";
        std::cin >> n;
    }
}


const unsigned int countWays(const int n) {
    if(n < vec.size()) {
        return vec[n];
    }

    if(vec.size() == 1) {
        vec.push_back(4); // 2 for one side and 2^2 = 4 for two sides
    }

    // countB is count of ways with a building at the end
    // countS is count of ways with a space at the end
    // prev_countB and prev_countS are previous values of countB and countS respectively.

    // Initialize countB and countS for one side
    unsigned int prev_countB;
    unsigned int prev_countS;

    for (unsigned int i = vec.size(); i <= n; ++i) {
        prev_countB = countB;
        prev_countS = countS;
        countS = prev_countB + prev_countS;
        countB = prev_countS;
        const unsigned int result = countS + countB;

        // Result for one side is sum of ways ending with building
        // and ending with space
        vec.push_back(result*result);
    }

    int result = countS + countB;

    // Result for 2 sides
    return vec[n];
}


const unsigned int recFibo(const int n) {
    if(n < vecfibo.size()) {
        return vecfibo[n];
    } else {
        const unsigned int tmp = recFibo(n-1) + recFibo(n-2);
        vecfibo.push_back(tmp);
        return tmp;
    }
}


const unsigned int countWaysFibo(const int n) {
    for(unsigned int i = vec.size(); i <= n; ++i) {
        const unsigned int fibo = recFibo(i + 2);
        // Result for one side is sum of ways ending with building
        // and ending with space
        vec.push_back(fibo * fibo);
    }

    // Result for 2 sides
    return vec[n];
}
