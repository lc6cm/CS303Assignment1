#pragma once  

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void exists(string numbers[],int size);
void changeNum(string* numbers, int size);
void addNumberToEnd(string*& numbers, int& size);
void removeInteger(string*& numbers, int& size);