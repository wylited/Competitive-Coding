// S1 Solution source code

// Specfication
// The first line of input will be an integer n (0 ≤ n ≤ 10000). Each of the remaining n lines of input will contain a computer specification.
// computer name (a string of less than 20 characters)
// the RAM available (an integer R with 1 ≤ R ≤ 128)
// the CPU speed (an integer S with 1 ≤ S ≤ 4000)
// the disk drive space (an integer D with 1 ≤ D ≤ 3000)
// There is one space between the name, RAM, CPU speed and disk drive space on each line.

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <string>
#define INF 2147483647;
#define ll long long
#define looptill(h) for(int i = 0; i < h; i++)

using namespace std;

pair<int, int> largest2(int arr[], int n){
    int i;

    pair<int, int> maxval(0, 0);

    // Traverse array elements
    // from second and compare
    // every element with current max
    for (i = 1; i < n; i++)
        if (arr[i] > arr[maxval.first]){
            maxval.second = maxval.first;
            maxval.first = i;
        }


    return maxval;
}

int main(){
    int n;
    cin >> n;
    if (n == 0) {cout << 0 << endl; return 0;};

    string names[10000]; int ram[10000]; int cpu[10000]; int disk[10000]; int total[10000];

    looptill(n){
        string s; int r, c, d;
        cin >> s >> r >> c >> d;
        names[i] = s; ram[i] = r; cpu[i] = c; disk[i] = d; total[i] = ((2*r) + (3*c) + d);
    }

    // Output the 2 top models in order of their total score
    // If there is a tie pick the one with less letters in their name
    // If there is only one laptop, only output it.
    int top1 = 0, top2 = 0;
    top1 = largest2(total, n).first;
    top2 = largest2(total, n).second;
    if (top1 == top2){
        cout << names[top1] << endl;
    } else {
        cout << names[top1] << endl;
        cout << names [top2] << endl;
    }


    return 0;
}
z