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

Arrays::Arrays() {
	this->n = 0;
    this->max = 100;
    this->min = 0;
	this->randomArray = nullptr;
	this->ascendingArray = nullptr;
	this->descendingArray = nullptr;
    this->size = n;
}

Arrays::Arrays(int n, int max, int min) {
	this->n = n;
    if (max <= min) {
        this->max = 100;
        this->min = 0;
    }
    else {
        this->max = max;
        this->min = min;
    }
	this->randomArray = new int[n];
	this->ascendingArray = new int[n];
	this->descendingArray = new int[n];
    this->size = n;
	fillArrays();
}

Arrays::~Arrays() {
	delete this->randomArray;
	delete this->ascendingArray;
	delete this->descendingArray;
}

void Arrays::fillArrays(int max, int min) {
    if (max <= min) {
        this->max = 100;
        this->min = 0;
    }
    else {
        if (max != this->max)
            this->max = max;
        else if (min != this->min)
            this->min = min;
    }
    Sleep(1000);
	srand(time(NULL));
    int randValue = (rand() % ((this->max)-(this->min)) + this->min);
    for (int i = 0; i < this->n; i++) {
        this->randomArray[i] = randValue;
        this->ascendingArray[i] = randValue;
        this->descendingArray[i] = randValue;
        randValue = (rand() % ((this->max) - (this->min)) + this->min);
    }
    mergeSort(this->ascendingArray, 0, (this->n) - 1);
    int temp = 0;
    for (int i = n-1; i >=0; i--) {
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
	cout << "randomArray:" << endl;
	for (int i = 0; i < this->n; i++)
		cout << this->randomArray[i] << " ";
	cout << endl << "ascendingArray:" << endl;
	for (int i = 0; i < this->n; i++)
		cout << this->ascendingArray[i] << " ";
	cout << endl << "descendingArray:" << endl;
	for (int i = 0; i < this->n; i++)
		cout << this->descendingArray[i] << " ";
}