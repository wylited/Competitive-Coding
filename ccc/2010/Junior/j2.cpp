// J2 Solution source code

// Imports:
#include <iostream>
#include <cmath>


// Specification:
// 5 integers: a, b, c, d and e one seperate lines
// a > b and c > d.

// return 0 if success and 1 if error or unexpected case.
// O(2s), 2 for loops that iterate through s values in theworst case scenario
int main() {
    int a, b, c, d, s;
    std::cin >> a; std::cin >> b; std::cin >> c; std::cin >> d; std::cin >> s;
    int NSteps;
    int BSteps;

    while (NSteps < s) {
        NSteps += a - b;
    }
    while (BSteps < s) {
        BSteps += c - d;
    }

    switch(NSteps > BSteps){
        case true:
            std::cout << "Nikky" << std::endl;
            break;
        case false:
            std::cout << "Byron" << std::endl;
            break;
    }

    return 0;
}