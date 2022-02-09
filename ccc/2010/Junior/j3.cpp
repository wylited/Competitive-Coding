// J3 Solution source code

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#define INF 2147483647;
#define ll long long

using namespace std;

int main(){
    bool quit = false;
    int a = 0, b = 0, cmd, val;
    char c, cc;

    while(!quit){
        cin >> cmd;
        switch(cmd){
            case 1:
                cin >> c >> val;
                if (c == 'A') {a=val;}
				else {b=val;}
                break;

            case 2:
                cin >> c;
                cout << ((c =='A')? a : b) << endl;
                break;

            case 3:
                cin >> c >> cc;
                if (c == 'A') {a = a + ((cc == 'B')? b : a);}
                else {b = b + ((cc == 'A')? a : b);}
                break;

            case 4:
                break;
            
            case 5:
                break;
            
            case 6:
                break;
            
            case 7:
                quit = true;
                break;

        }
    }
    return 0;
}