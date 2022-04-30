#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Data oriented approach to the bus problem
// https://www.cambridgeinternational.org/Images/520646-june-2097-paper-21-pre-release-material.pdf

// Information - Punctuality Table.
// Each set value represents the punctuality of the bus at the given date and time period.
// There are 6 buses labeled from A-F.
// There are 5 days the bus operates on, Monday to Friday.
// The bus services 4 times a day.
// This toatls in 120 values.

// The values are stored in a 2d array 6 by 20.
// The first dimension is the bus, the second is the day and time period.

// The X axis is set in the following order:
// Bus A
// Bus B
// Bus C
// Bus D
// Bus E
// Bus F

// The Y axis is set in the following order:
// Mon1, Mon2, Mon3, Mon4
// Tue1, Tue2, Tue3, Tue4
// Wed1, Wed2, Wed3, Wed4
// Thu1, Thu2, Thu3, Thu4
// Fri1, Fri2, Fri3, Fri4

// Positive numbers represent minutes early, negative numbers represent minutes late and 0 represents the bus having been on time

int table[6][20] = {
    {
        0, 4, -5, -1, // Monday
        0, 0, 0, 8, // Tuesday
        0, 3, 0, 1, // Wednesday
        2, 4, 3, 1, // Thursday
        2, -2, 4, -2 // Friday  
    }, // Bus A
    {
        0, 2, 1, -1, // Monday
        1, 0, 0, 8, // Tuesday
        0, 0, 0, 1, // Wednesday
        1, 0, 2, -2, // Thursday
        0, 0, 2, -2 // Friday
    }, // Bus B
    {
        2, -2, -2, 1, // Monday
        0, -3, 0, -1, // Tuesday
        -1, -1, 1, -1, // Wednesday
        -1, 0, 1, -1, // Thursday
        -2, 0, 1, 2 // Friday
    }, // Bus C
    {
        1, 2, 0, 0, // Monday
        0, 0, 0, 0, // Tuesday
        0, 0, 0, 0, // Wednesday
        0, 0, 0, 0, // Thursday
        0, 0, 0, 0 // Friday
    }, // Bus D
    {
        -1, -10, 0, 1, // Monday
        -1, -4, 1, 3, // Tuesday
        -1, -2, 2, -1, // Wednesday
        -2, 0, -3, 0, // Thursday
        -4, 0, 1, 0 // Friday
    }, // Bus E
    {
        0, -3, 0, 1, // Monday
        -5, -5, -2, 0, // Tuesday
        -5, 0, -3, 0, // Wednesday
        -5, 0, 1, -2, // Thursday
        -4, 0, 1, -5 // Friday
    } // Bus F
}; // Intialize the 2d array.

int chosebus = 0, choseday = 0, chosetime = 0, punctuality = 0, intinput = 0, total = 0; // The user's choice of bus, day and time.

// Statstics enum
enum stats {
    TOTLATE, AVERAGE, AVERAGELATE, MOSTLATE, LATEONDAY,
};

void change(int bus, int date, int time, int punctuality) {
    // Change the set punctuality depending on the user's input.
    table[bus - 1][((date-1) * 4) + (time-1)] = punctuality;
}

// Ask the user if they want to make a specific schedule.
void askcustom() {
    cout << "Would you like to make a change? (y/n)" << endl;
    string input;
    cin >> input;
    if (input == "y") {
        cout << "Please enter the bus number (1-6):" << endl;
        cin >> chosebus;
        cout << "Please enter the day (1-5):" << endl;
        cin >> choseday;
        cout << "Please enter the time (1-4):" << endl;
        cin >> chosetime;
        cout << "Please enter the punctuality value:" << endl;
        cin >> punctuality;
        change(chosebus, choseday, chosetime, punctuality);
        cout << "Would you like to make another change? (y/n)" << endl;
        cin >> input;
        if (input == "y") {
            askcustom();
        } else {
            return;
        }
    }
    else {
        return;
    }
}

int totlate(int busroute){
    // Sum up the total lates for a bus route.
    for (int i = 0; i < 20; i++) {
        if (table[busroute - 1][i] < 0) {
            total += table[busroute - 1][i];
        }
    } //I really didn't want to use a for loop but do I have a choice? not really idk.
    // Cycles 20 times
    return total;
}

int avglate(int busroute){
    return totlate(busroute)/20;
}

int average(int busroute){
    total = 0;
    // Sum up the total lates for a bus route.
    for (int i = 0; i < 20; i++) {
        total += table[busroute][i];
    } //I really didn't want to use a for loop but do I have a choice? not really idk.
    // Cycles 20 times
    return total/20;
}

char mostlate(){
    // Find the bus with the most late punctuality.
    int max = 0;
    int maxbus = 0;
    for (int i = 0; i < 6; i++) {
        if (max < totlate(i)) {
            max = totlate(i);
            maxbus = i;
        }
    }
    switch(maxbus){
        case 0: return 'A'; break;
        case 1: return 'B'; break;
        case 2: return 'C'; break;
        case 3: return 'D'; break;
        case 4: return 'E'; break;
        case 5: return 'F'; break;
    }
    return maxbus;
}

void analysis(){
    bool exit = false;
    // Loop until the user wants to stop anlaysing
    while(exit == false){
        // Print all of the buses that were late and how late they were by on (day *4) + time.
        cout << "Which day? (1-5)" << endl;
        cin >> choseday;
        cout << "Which time period? (1-4)" << endl;
        cin >> chosetime;
        for (int i = 0; i < 6; i++) {
            if (table[i][((choseday-1) * 4) + (chosetime-1)] < 0) {
                cout << "Bus " << i + 1 << " was " << table[i][((choseday-1) * 4) + (chosetime-1)] << " minutes late." << endl;
            }
        }
        cout << "Would you like to see another statistic? (y/n)" << endl;
        cin >> exit;
    }
}

int main(){
    askcustom();
    
    // Print all of the calculateed statstics.
    cout << "The total late time for bus A was " << totlate(0) << " minutes." << endl;
    cout << "The total late time for bus B was " << totlate(1) << " minutes." << endl;
    cout << "The total late time for bus C was " << totlate(2) << " minutes." << endl;
    cout << "The total late time for bus D was " << totlate(3) << " minutes." << endl;
    cout << "The total late time for bus E was " << totlate(4) << " minutes." << endl;
    cout << "The total late time for bus F was " << totlate(5) << " minutes." << endl;
    cout << "The average late time for bus A was " << avglate(0) << " minutes." << endl;
    cout << "The average late time for bus B was " << avglate(1) << " minutes." << endl;
    cout << "The average late time for bus C was " << avglate(2) << " minutes." << endl;
    cout << "The average late time for bus D was " << avglate(3) << " minutes." << endl;
    cout << "The average late time for bus E was " << avglate(4) << " minutes." << endl;
    cout << "The average late time for bus F was " << avglate(5) << " minutes." << endl;
    cout << "The average punctuality for bus A was " << average(0) << " minutes." << endl;
    cout << "The average punctuality for bus B was " << average(1) << " minutes." << endl;
    cout << "The average punctuality for bus C was " << average(2) << " minutes." << endl;
    cout << "The average punctuality for bus D was " << average(3) << " minutes." << endl;
    cout << "The average punctuality for bus E was " << average(4) << " minutes." << endl;
    cout << "The average punctuality for bus F was " << average(5) << " minutes." << endl;
    cout << "The bus with the most late punctuality was bus " << mostlate() << "." << endl;
    

    return 0;
}

