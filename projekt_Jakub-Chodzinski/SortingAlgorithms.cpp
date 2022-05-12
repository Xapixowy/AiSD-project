#include "SortingAlgorithms.h"

#include <iostream>

using namespace std;

SortingAlgorithms::SortingAlgorithms(int *array, int size, bool sort, int algorithm) {
	this->array = new int[size];
	this->dominantOperations = 0;
	this->algorithm = algorithm;
	setArray(array, size);
	if (sort) {
		if (algorithm == 0)
			this->sort(0);
		else if (algorithm == 1)
			this->sort(1);
		else if (algorithm == 2)
			this->sort(2);
	}
};

SortingAlgorithms::~SortingAlgorithms() {
	delete[] this->array;
};

void SortingAlgorithms::printArray() {
	cout << "Array:\n";
	for (int i = 0; i < this->arraySize; i++)
		cout << this->array[i] << " ";
	cout << "\n";
};

void SortingAlgorithms::printDominantOperations() {
	cout << "Dominant operations: " << dominantOperations << "\n";
};

void SortingAlgorithms::printAlgorithm() {
	cout << "Algorithm: " << getAlgorithm() << "\n";
};

int* SortingAlgorithms::getArray() {
	return this->array;
}

unsigned long long SortingAlgorithms::getDominantOperations() {
	return this->dominantOperations;
}

string SortingAlgorithms::getAlgorithm() {
	if (this->algorithm == 0)
		return "bubbleSort";
	else if (this->algorithm == 1)
		return "insertionSort";
	else if (this->algorithm == 2)
		return "mergeSort";
}

void SortingAlgorithms::setArray(int* array, int size) {
	this->arraySize = size;
	this->array = new int[this->arraySize];
	for (int i = 0; i < this->arraySize; i++)
		this->array[i] = array[i];
};

void SortingAlgorithms::sort(int algorithm) {
	this->algorithm = algorithm;
	if (algorithm == 0)
		bubbleSort(this->array, this->arraySize);
	else if (algorithm == 1)
		insertionSort(this->array, this->arraySize);
	else if (algorithm == 2)
		mergeSort(this->array, 0, (this->arraySize) - 1);
}

void SortingAlgorithms::bubbleSort(int* array, int size) {
	int temp;
	bool flag;
	for (int i = 0; i < size; i++) {
		flag = true;
		for (int j = 0; j < size - i - 1; j++) {
			this->dominantOperations++;
			if (array[j] > array[j + 1]) {
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = false;
			}
		}
		if (flag)
			break;
	}
}

void SortingAlgorithms::insertionSort(int* array, int size) {
	int dominantOperations[2] = { 0,0 };
	bool flag;
	int i, key, j;
	for (i = 1; i < size; i++) {
		flag = false;
		key = array[i];
		j = i - 1;
		dominantOperations[0]++;
		while (j >= 0 && array[j] > key) {
			flag = true;
			dominantOperations[1]++;
			array[j + 1] = array[j];
			j = j - 1;
		}
		if (flag)
			dominantOperations[1]--;
		array[j + 1] = key;
	}
	this->dominantOperations = dominantOperations[0] + dominantOperations[1];
}

void SortingAlgorithms::merge(int* array, int left, int middleValue, int right) {
	int i, j, k;
	int n1 = middleValue - left + 1;
	int n2 = right - middleValue;
	int* Left = new int[n1];
	int* Right = new int[n2];
	for (i = 0; i < n1; i++)
		Left[i] = array[left + i];
	for (j = 0; j < n2; j++)
		Right[j] = array[middleValue + 1 + j];
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		this->dominantOperations++;
		if (Left[i] <= Right[j])
		{
			array[k] = Left[i];
			i++;
		}
		else
		{
			array[k] = Right[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		this->dominantOperations++;
		array[k] = Left[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		this->dominantOperations++;
		array[k] = Right[j];
		j++;
		k++;
	}
}

void SortingAlgorithms::mergeSort(int* array, int left, int right) {
	if (left < right)
	{
		int middleValue = left + (right - left) / 2;
		mergeSort(array, left, middleValue);
		mergeSort(array, middleValue + 1, right);
		merge(array, left, middleValue, right);
	}
}