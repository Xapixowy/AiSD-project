#include "arrays.h"

#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

Arrays::Arrays(int size, int max, int min) {
	this->randomArray = new int[size];
	this->ascendingArray = new int[size];
	this->descendingArray = new int[size];
	fillArrays(size, max, min);
}

Arrays::~Arrays() {
	delete[] this->randomArray;
	delete[] this->ascendingArray;
	delete[] this->descendingArray;
}

void Arrays::fillArrays(int size, int max, int min) {
    this->size = size;
    if (max < min) {
        this->max = 100;
        this->min = 1;
	}
	else if (max == min) {
		this->max = this->size;
		this->min = 1;
	}
    else {
        this->max = max;
        this->min = min;
    }
    Sleep(100);
	srand(time(NULL));
    int randValue = (rand() % ((this->max) + 1) + this->min);
	int temp = this->size;
    for (int i = 0; i < this->size; i++) {
        this->randomArray[i] = randValue;
		this->ascendingArray[i] = i + 1;
        this->descendingArray[i] = temp--;
        randValue = (rand() % ((this->max) + 1) + this->min);
    }
}

int* Arrays::getArray(int type) {
	if (type == 0)
		return this->randomArray;
	else if (type == 1)
		return this->ascendingArray;
	else if (type == 2)
		return this->descendingArray;
	else
		return nullptr;
}

void Arrays::printArrays() {
    cout << (char)(175) << " Arrays:" << endl;
	cout << "randomArray:" << endl;
	for (int i = 0; i < this->size; i++)
		cout << this->randomArray[i] << " ";
	cout << endl << "ascendingArray:" << endl;
	for (int i = 0; i < this->size; i++)
		cout << this->ascendingArray[i] << " ";
	cout << endl << "descendingArray:" << endl;
	for (int i = 0; i < this->size; i++)
		cout << this->descendingArray[i] << " ";
    cout << endl;
}