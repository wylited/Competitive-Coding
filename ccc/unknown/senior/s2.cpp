// S2 Solution source code.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <string>
#include <bitset>
#define INF 2147483647;
#define ll long long

using namespace std;

int main() {
    string binput;
    bool quit = false;
    cin >> binput;
    int n = stoi(binput, 0, 2);
    int start = 1, end = n/2;
    int mid, sqr;

    while (!quit){
        mid = (start + end)/2;
        sqr = mid * mid;
        if(sqr == n){
            quit = true;
            cout << std::bitset<16>(mid) << endl;
            break;
        }
        if(sqr < n){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return 0;
}