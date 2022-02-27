// J5 Solution source code

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#define INF 2147483647;
#define ll long long
#define looptill(h) for(int i = 0; i < h; i++)

using namespace std;

// 8 x 8 chessboard
// The knight jumps in a l shape
// The first 2 values inputed are the starting position
// The next 2 values inputed are the ending position
// Calculate the smallest amount of moves required to get from the start to end
//! Note that the knight is not allowed to move off the board during the sequence of moves.
int main() {
    int moves = 0; // 6 is the maxmimum amount of moves a knight needs to make to reach any position on a 8x8 board
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int cx = x1, cy = y2;
    int opx1 = 0, opx2 = 0, opy1 = 0, opy2 = 0;
    int quadrant;
    bool reachdest = false;

    while (!reachdest) {
        int dx = x2 - cx, dy = y2 - cy;
        reachdest = (x2 == cx && y2 == cy)? true : false;

        if (dx >= 0) {
            if (dy >= 0) {
                quadrant = 1;   // Top left quadrant
                opx1 = cx + 1; opy1 = cx + 2;
                opx2 = cx + 2; opy2 = cx + 1;

            } else {
                quadrant = 4;   // Bottom left quadrant
                opx1 = cx + 1; opy1 = cx - 2;
                opx2 = cx + 2; opy2 = cx - 1;

            }
        } else {
            if (dy >= 0) {
                quadrant = 2;   // Top right quadrant
                opx1 = cx - 1; opy1 = cx + 2;
                opx2 = cx - 2; opy2 = cx + 1;
                
            } else {
                quadrant = 3;   // Top left quadrant
                opx1 = cx - 1; opy1 = cx - 2;
                opx2 = cx - 2; opy2 = cx - 1;

            }
        }
        cout << opx1 << " " << opy1 << " | " << opx2 << " " << opy2 << endl;
        moves++;
        break;
    }
    

    cout << moves << endl;
    return 0;
}