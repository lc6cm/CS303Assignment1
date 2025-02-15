// Lupe Campos Soto
//CS-303

#include <iostream>
#include "Functions.h"
#include <fstream>
using namespace std;

int main() {
    ifstream InputFile("A1input.txt");
    if (!InputFile) { //Check if file is valid
        cerr << "Error Opening File" << endl;
        return 1;
    }

    string num;
    string* numbers = new string[100];  // Dynamically allocate memory for the array
    int arrSize = 0;

    // Read numbers from the file and store them in the array
    while (InputFile >> num && arrSize < 100) {  // Ensure not exceeding the array size
        numbers[arrSize] = num;
        arrSize++;
    }

    InputFile.close();

    // Call the functions
    exists(numbers, arrSize); 
    changeNum(numbers, arrSize);       
    addNumberToEnd(numbers, arrSize); 
    removeInteger(numbers, arrSize);

    

    return 0;
}
