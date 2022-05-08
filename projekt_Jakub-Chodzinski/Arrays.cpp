#include "arrays.h"

#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

void merge(int array[], int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;
    auto* leftArray = new int[subArrayOne],
        * rightArray = new int[subArrayTwo];
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];
    auto indexOfSubArrayOne = 0,
        indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;
    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

Arrays::Arrays(int size, int max, int min) {
	this->randomArray = new int[size];
	this->ascendingArray = new int[size];
	this->descendingArray = new int[size];
	fillArrays(size, max, min);
}

Arrays::~Arrays() {
	delete this->randomArray;
	delete this->ascendingArray;
	delete this->descendingArray;
}

void Arrays::fillArrays(int size, int max, int min) {
    this->size = size;
    if (max <= min) {
        this->max = 100;
        this->min = 0;
    }
    else {
        this->max = max;
        this->min = min;
    }
    Sleep(100);
	srand(time(NULL));
    int randValue = (rand() % ((this->max) + 1) + this->min);
    for (int i = 0; i < this->size; i++) {
        this->randomArray[i] = randValue;
        this->ascendingArray[i] = randValue;
        this->descendingArray[i] = randValue;
        randValue = (rand() % ((this->max) + 1) + this->min);
    }
    mergeSort(this->ascendingArray, 0, (this->size) - 1);
    int temp = 0;
    for (int i = size -1; i >=0; i--) {
        this->descendingArray[i] = this->ascendingArray[temp];
        temp++;
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