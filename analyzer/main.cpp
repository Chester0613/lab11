
/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Joandry A. Irizarry Roman]
 * Lab: 11 - Arrays and Structs
 * Description: Stores election observations in an array,
 *              validates input, and controls the menu.
 * Due Date: [Nov/1/2026]
 */

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include "observation.h"
#include "display.h"

using namespace std;

int main() {
    const int CAPACITY = 100;
    Observation observations[CAPACITY] = {};

    int requestedObservations = 0;
    int menuChoice = 0;

    // Request between 1 and 3 observations
    cout << "Enter number of observations (1-3): ";

    while (!(cin >> requestedObservations) ||
           requestedObservations < 1 ||
           requestedObservations > 3) {

        cout << "Invalid input. Enter a number from 1 to 3: ";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Enter observation data
    for (int i = 0; i < requestedObservations; i++) {

        cout << "\nObservation " << i + 1 << endl;

        cout << "Enter ID: ";
        while (!(cin >> observations[i].id)) {
            cout << "Invalid ID. Enter a whole number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter state: ";
        cin >> observations[i].state;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter county: ";
        getline(cin, observations[i].county);

        cout << "Enter total votes: ";
        while (!(cin >> observations[i].totalVotes) ||
               observations[i].totalVotes < 0) {

            cout << "Invalid input. Enter a non-negative number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter Democratic votes: ";
        while (!(cin >> observations[i].democraticVotes) ||
               observations[i].democraticVotes < 0) {

            cout << "Invalid input. Enter a non-negative number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter Republican votes: ";
        while (!(cin >> observations[i].republicanVotes) ||
               observations[i].republicanVotes < 0) {

            cout << "Invalid input. Enter a non-negative number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter Democratic share (0-100): ";
        while (!(cin >> observations[i].democraticShare) ||
               observations[i].democraticShare < 0 ||
               observations[i].democraticShare > 100) {

            cout << "Invalid input. Enter a percentage from 0 to 100: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        // Mark the observation as occupied
        observations[i].isEmpty = false;
    }

    // Main menu
    do {
        cout << "\nCoRe Data Analyzer - Lab 11 prototype\n";
        cout << "1. Display Data Frame\n";
        cout << "11. Exit application\n";
        cout << "Enter option number: ";

        while (!(cin >> menuChoice)) {
            cout << "Invalid input. Enter an option number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (menuChoice) {

            case 1: {
                int displayed = 0;

                cout << "\nDATA FRAME\n";

                cout << left
                     << setw(8) << "ID"
                     << setw(10) << "State"
                     << setw(24) << "County"
                     << setw(15) << "Total Votes"
                     << setw(15) << "Dem Votes"
                     << setw(15) << "Rep Votes"
                     << setw(12) << "Dem Share"
                     << endl;

                cout << string(99, '-') << endl;

                for (int i = 0; i < CAPACITY; i++) {
                    if (!observations[i].isEmpty) {
                        displayObservation(observations[i]);
                        displayed++;
                    }
                }

                if (displayed == 0) {
                    cout << "The dataset is empty." << endl;
                } else {
                    cout << "\nObservations displayed: "
                         << displayed << endl;
                }

                break;
            }

            case 11:
                cout << "Session ended." << endl;
                break;

            default:
                cout << "Invalid option." << endl;
                break;
        }

    } while (menuChoice != 11);

    return 0;
}

/*
 * Analysis:
 *
 * 1. Why can observation ID 151 be stored at array index 0?
 *
 * Because the ID is just a value stored in the record.
 * The array index represents the position in memory.
 *
 * 2. What initializes unused slots as empty, and when does
 *    a slot become occupied?
 *
 * The array initialization and isEmpty = true make the
 * slots empty. A slot becomes occupied after entering
 * its data and setting isEmpty to false.
 *
 * 3. Why does Display examine the capacity but print
 *    only occupied observations?
 *
 * Because the array has 100 spaces, but not all of them
 * contain data. The program skips empty slots.
 *
 * 4. What record is passed to displayObservation on each
 *    function call, and is it a copy?
 *
 * Each occupied Observation is passed to the function.
 * Yes, the function receives a copy of the record.
 *
 * 5. Why does the build command include main.cpp and
 *    display.cpp but not the headers?
 *
 * Because the .cpp files contain the function definitions.
 * The headers are included automatically using #include.
 */
