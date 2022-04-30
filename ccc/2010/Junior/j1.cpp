// J1 Solution source code

// Imports:
#include <iostream>
#include <cmath>


// Specification:
// Input of n, where i is an integer between 1..10
// Output the different ways you can add numbers between 1..i to get i

// return 0 if success and 1 if error or unexpected case.
int main() {
    int n;
    std::cin >> n;
    // number of ways to add 1..n to get n
    // 
    int options = floor(n/2);

    std::cout << options << std::endl;
    return 0;
}