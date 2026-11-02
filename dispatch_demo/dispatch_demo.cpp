
/*
 * Course: COEN 2210 - Introduction to Programming
 * Name: [Joandry A. Irizarry Roman]
 * Lab: 11 - Arrays and Structs
 * Description: Records shipment information and displays
 *              a summary using a struct and a function.
 * Due Date: [Nov/1/2026]
 */

#include <iostream>
#include <string>
using namespace std;

struct DispatchRecord {
    string destination;
    int boxCount = 0;
};

// Function prototype
void displayDispatch(DispatchRecord record);

int main() {
    DispatchRecord shipment = {};

    cout << "Enter shipment destination: ";
    getline(cin, shipment.destination);

    cout << "Enter number of boxes: ";
    cin >> shipment.boxCount;

    while (shipment.boxCount < 1) {
        cout << "Enter a positive number of boxes: ";
        cin >> shipment.boxCount;
    }

    cout << "Destination recorded: "
         << shipment.destination << endl;

    // Function call
    displayDispatch(shipment);

    return 0;
}

// Function definition
void displayDispatch(DispatchRecord record) {
    cout << "Dispatch summary" << endl;
    cout << "Destination: " << record.destination << endl;
    cout << "Boxes: " << record.boxCount << endl;
}

/*
 * Analysis:
 *
 * 1. What is the difference between DispatchRecord and shipment?
 *
 * DispatchRecord is the struct type that defines the data.
 * shipment is a variable created using that struct.
 *
 * 2. Which members are copied when displayDispatch(shipment) is called?
 *
 * The destination and boxCount members are copied
 * into the function parameter.
 *
 * 3. Why would changing record.boxCount inside the function
 *    leave shipment.boxCount unchanged?
 *
 * Because the function receives a copy of shipment.
 * Changing the copy does not change the original variable.
 */
