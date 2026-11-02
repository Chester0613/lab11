
/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Joandry A. Irizarry Roman]
 * Lab: 11 - Arrays and Structs
 * Description: Displays one election observation
 *              in an aligned table row.
 * Due Date: [Nov/1/2026]
 */

#include <iostream>
#include <iomanip>
#include "display.h"

using namespace std;

void displayObservation(Observation observation) {
    cout << left
         << setw(8) << observation.id
         << setw(10) << observation.state
         << setw(24) << observation.county
         << setw(15) << observation.totalVotes
         << setw(15) << observation.democraticVotes
         << setw(15) << observation.republicanVotes
         << setw(12) << fixed << setprecision(2)
         << observation.democraticShare;

    cout << endl;
}
