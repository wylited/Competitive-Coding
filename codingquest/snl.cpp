#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Tile {
public:
    int value;
    // Tile* next;
    // Tile* previous;
};

int main(){
    Tile board[399];
    ifstream file;
    file.open("/home/wylited/Documents/coding/Competitive Programming/codingquest/snl.txt");
    
    cout << "I reached here" << endl;

    if(!file) {
        cout << "unable to open file1" << endl;
        return(0);
    }

    cout << "I reached here 2" << endl;
    
    // The first 400 values of the file are the tiles and each of their value.
    // Loop through them and add them to the board.
    for (int i = 0; i < 400; i++) {
        int value;
        file >> value;
        board[i].value = value;
    }

    cout << "I reached here 3" << endl;
    // Now we have the board, we can start the game.
    // The next 1000 values represent the moves by player one and player two.
    int p1roll = 0, p2roll = 0;
    int p1pos = 0, p2pos = 0;
    int p1moves = 0, p2moves = 0;
    int tval1 = 0, tval2 = 0;
    cout << "I reached here 4" << endl;
    // print out all the tilevalues in the board
    // for (int i = 0; i < 399; i++) {
    //     cout << board[i].value << " ";
    // }

    // bool won = false;
    // while (!won){
    //     file >> p1roll >> p2roll; // Take in the rolled values.
    //     cout << "p1roll: " << p1roll << " | p2roll: " << p2roll << endl;
    //     ++p1moves; ++p2moves; // Update the moves done.
    //     p1pos += p1roll; // Update the position of player one.
    //     p2pos += p2roll; // Update the position of player two.

    //     // cout << "Player 1 rolled " << p1roll << " and player 2 rolled " << p2roll << endl;
    //     // cout << "Player 1 is at " << p1pos << " and player 2 is at " << p2pos << endl;
    //     // cout << "Player 1 has done " << p1moves << " moves and player 2 has done " << p2moves << " moves." << endl;

    //     // Change the position of the players depending on their tile until they hit a tile that doesn't move them.
        // while (board[p1pos].value != 0) {
        //     p1pos += board[p1pos].value;
        // }
        // while (board[p2pos].value != 0) {
        //     p2pos += board[p2pos].value;
        // }
    //     cout << p1moves << ": " << p1pos << " " << p2moves << ": " << p2pos << endl;
    //     // Check if either of them won, IE if they hit the end of the board.
    //     if (p1pos >  399) {
    //         cout << "Player 1 won in " << p1moves << " moves." << endl;
    //         won = true;
    //     }
    //     if (p2pos >  399) {
    //         cout << "Player 2 won in " << p2moves << " moves." << endl;
    //         won = true;
    //     }
    // }

    for (int i = 0; i<500; i += 2){
        // Loop through them and find which one reaches tile 399 first.
        // If player one reaches tile 399 first, print the number of moves it took.
        // If player two reaches tile 399 first, print the number of moves it took multiplied by 2.
        file >> p1roll >> p2roll;

        // Update the moves.
        ++p1moves; ++p2moves;
        
        p1pos += p1roll; p2pos += p2roll;

        tval1 = board[p1pos].value;
        tval2 = board[p2pos].value;
        while (board[p1pos].value != 0) {
            p1pos += board[p1pos].value;
        }
        while (board[p2pos].value != 0) {
            p2pos += board[p2pos].value;
        }

        cout << p1moves << ": " << p1pos << " " << p2moves << ": " << p2pos << endl;
    }
    file.close();
    return 0;
}