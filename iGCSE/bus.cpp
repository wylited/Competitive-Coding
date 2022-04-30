#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Indexes? perhaps would make the dimensional array easier to navigate.
// Unicode characters because c++ is just like that.
enum buses { A=65, B=66, C=67, D=68, E=69, F=70 }; 
enum days { Mon=1, Tue=2, Wed=3, Thu=4, Fri=5, Sat=6, Sun=7 };

void changetime(int schedule[6][5][4], int bus, int day, int time){
    // Prompt for the new time
    cout << "What would you like to change the time to?" << endl;
    int newTime;
    cin >> newTime;
    // Change the time
    schedule[bus][day][time-1] = newTime;
}

void changeday(int schedule[6][5][4], int bus, int day){
    int time;
    switch(day){
        case 1:
            // Prompt for the time
            cout << "Which time would you like to change? (1, 2, 3, 4)" << endl;
            cin >> time;
            // Prompt for the new time
            changetime(schedule, bus, day, time);
            break;
        case 2:
            // Prompt for the time
            cout << "Which time would you like to change? (1, 2, 3, 4)" << endl;
            cin >> time;
            // Prompt for the new time
            changetime(schedule, bus, day, time);
            break;
        case 3:
            // Prompt for the time
            cout << "Which time would you like to change? (1, 2, 3, 4)" << endl;
            cin >> time;
            // Prompt for the new time
            changetime(schedule, bus, day, time);
            break;
        case 4:
            // Prompt for the time
            cout << "Which time would you like to change? (1, 2, 3, 4)" << endl;
            cin >> time;
            // Prompt for the new time
            changetime(schedule, bus, day, time);
            break;
        case 5:
            // Prompt for the time
            cout << "Which time would you like to change? (1, 2, 3, 4)" << endl;
            cin >> time;
            // Prompt for the new time
            changetime(schedule, bus, day, time);
    }
}

int changebus(int schedule[6][5][4]){
    // Prompt for the bus
    cout << "Which bus would you like to change? (A, B, C, D, E, F)" << endl;
    char bus; int day;
    cin >> bus;
    switch(bus){
        case 'A':
            // Prompt for the day
            cout << "Which day would you like to change? (Mon: 1, Tue: 2, Wed: 3, Thu: 4, Fri: 5)" << endl;
            cin >> day;
            changeday(schedule, bus, day);
            break;
        case 'B':
            // Prompt for the day
            cout << "Which day would you like to change? (Mon: 1, Tue: 2, Wed: 3, Thu: 4, Fri: 5)" << endl;
            cin >> day;
            changeday(schedule, bus, day);
            break;
        case 'C':
            // Prompt for the day
            cout << "Which day would you like to change? (Mon: 1, Tue: 2, Wed: 3, Thu: 4, Fri: 5)" << endl;
            cin >> day;
            changeday(schedule, bus, day);
            break;
        case 'D':
            // Prompt for the day
            cout << "Which day would you like to change? (Mon: 1, Tue: 2, Wed: 3, Thu: 4, Fri: 5)" << endl;
            cin >> day;
            changeday(schedule, bus, day);
            break;
        case 'E':
            // Prompt for the day
            cout << "Which day would you like to change? (Mon: 1, Tue: 2, Wed: 3, Thu: 4, Fri: 5)" << endl;
            cin >> day;
            changeday(schedule, bus, day);
            break;
        case 'F':
            // Prompt for the day
            cout << "Which day would you like to change? (Mon: 1, Tue: 2, Wed: 3, Thu: 4, Fri: 5)" << endl;
            cin >> day;
            changeday(schedule, bus, day);
            break;
    }
}

int main() {
    // the input buffer
    string input;
    // The preset schedule of all the bus times.
    // in a 3d array, the first dimension is the bus, the second is the day, and the third is the time.
    // [buses (1-6)][days (1-5)][times (1-4)]
    int schedule[6][5][4] = {
                {
                    { 0, 4, -5, -1 }, // Monday
                    { 0, 0, 0, 8 }, // Tuesday 
                    { 0, 3, 0, 1 }, // Wednesday
                    { 2, 4, 3, 1 }, // Thursday
                    { 2, -2, 4, -2}, // Friday
                }, // Bus A
                {
                    { 0, 2, 1, -1 }, // Monday
                    { 1, 0, 0, 8 }, // Tuesday
                    { 0, 0, 0, 1 }, // Wednesday
                    { 0, 0, 0, 1 }, // Thursday
                    { 1, 0, 2, -2 }, // Friday
                }, // Bus B
                {
                    { 2, -2, -2, 1 }, // Monday
                    { 0, -3, 0, -1 }, // Tuesday
                    { -1, -1, 1, -1 }, // Wednesday
                    { -1, 0, 1, -1 }, // Thursday
                    { -2, 0, 1, 2 }, // Friday
                }, // Bus C
                {
                    { 1, 2, 0, 0 }, // Monday
                    { 0, 0, 0, 0 }, // Tuesday
                    { 0, 0, 0, 0 }, // Wednesday
                    { 0, 0, 0, 0 }, // Thursday
                    { 0, 0, 0, 0 }, // Friday
                }, // Bus D
                {
                    { -1, -10, 0, 1 }, // Monday
                    { -1, -4, 1, 3 }, // Tuesday
                    { -1, -2, 2, -1 }, // Wednesday
                    { -2, 0, -3, 0 }, // Thursday
                    { -4, 0, 1, 0 }, // Friday
                }, // Bus E
                {
                    { 0, -3, 0, 1 }, // Monday
                    { -5, -5, -2, 0 }, // Tuesday
                    { -5, 0, -3, 0 }, // Wednesday
                    { -5, 0, 1, -2 }, // Thursday
                    { -4, 0, 1, -5 }, // Friday
                }, // Bus F
    };
    
    // Welcome the user to the bus program.
    cout << "Welcome to the bus program!" << endl;
    
    // Prompt if they want to input a custome schedule
    cout << "Would you like to input a custom schedule? (y/n)" << endl;
    cin >> input;
    // Check if they want to input a custom schedule
    if (input == "y") {
        changebus(schedule) >> schedule;
    }
}