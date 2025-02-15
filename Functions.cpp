#include "Functions.h"  
#include <iostream>
#include <string>
using namespace std;


void exists(string numbers[], int size) {
    int find;

    while (true) {
        try {
            cout << "What number would you like to find?\n";
            cin >> find;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Please enter a valid integer.\n";
                continue;
            }

            bool found = false;
            for (int i = 0; i < size; i++) {
                string findstr = to_string(find);
                if (numbers[i] == findstr) {
                    cout << "Found " << numbers[i] << " at index " << i << "\n";
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << find << " not in file\n";
            }
            break;

        }
        catch (const std::exception& e) {
            cout << "Error: " << e.what() << "\n";
            break; 
        }
    }
}


void changeNum(string* numbers, int size) {
    string orig;
    string change;

    // Ask the user for the index they want to change
    cout << "What number would you like to change?\n";
    cin >> orig;

    // Ask the user for the new value
    cout << "What would you like to change it to?\n";
    cin >> change;

    int origNum;
    bool validIndex = false;

    // Keep asking for a valid index until it's entered
    while (!validIndex) {
        try {
            origNum = stoi(orig);  // Convert the string to an integer

            // Check if the index is within bounds
            if (origNum >= 0 && origNum < size) {
                validIndex = true;  // Index is valid, exit the loop
            }
            else {
                cout << "Index out of bounds. Please choose a valid index between 0 and " << size - 1 << ".\n";
                cout << "What number would you like to change?\n";
                cin >> orig;
            }
        }
        catch (invalid_argument& e) {
            cout << "Error: Invalid input. Please enter a valid integer.\n";
            cout << "What number would you like to change?\n";
            cin >> orig;  // Ask for input again if conversion fails
        }
    }

    // Now we know the index is valid, change the value at that index
    int newNum = origNum - 1;
    numbers[newNum] = change;
    cout << "Number at index " << origNum << " has been changed to " << change << "\n";

    // Output the updated array
    cout << "Updated array:\n";
    for (int i = 0; i < size; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

void addNumberToEnd(string*& numbers, int& size) {
    string newNumber;

   
    cout << "What number would you like to add to the end of the array: ";// Ask user for input
    cin >> newNumber;

    
    string* newArray = new string[size + 1];

    for (int i = 0; i < size; ++i) {
        newArray[i] = numbers[i];
    }
    newArray[size] = newNumber;

    delete[] numbers;

    numbers = newArray;

    ++size;

    cout << "Updated array\n";
    for (int i = 0; i < size; ++i) {
        cout << numbers[i] << " ";
    }
    cout << endl;


    
}


void removeInteger(string*& numbers, int& size) {
    int index;
        cout << "Which  index would you like to remove? ";
        cin >> index;

        if (cin.fail() || index < 0 || index >= size) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid index! Please enter a valid index between 0 and " << size - 1 << ".\n";
            return;
        }

        // Shift all elements to the left starting from the index to remove
        for (int i = index; i < size - 1; i++) {
            numbers[i] = numbers[i + 1];
        }

        // Optionally, set the last element to a default value (not necessary, but useful)
        numbers[size - 1] = "";

        // Decrease the size of the array
        --size;
        cout << "Updated array\n";
        for (int i = 0; i < size; ++i) {
            cout << numbers[i] << " ";
        }
        cout << endl;
        
    

}
        


