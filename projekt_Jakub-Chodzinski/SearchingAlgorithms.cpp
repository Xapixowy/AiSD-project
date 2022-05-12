#include "SearchingAlgorithms.h"

#include <iostream>

using namespace std;

SearchingAlgorithms::SearchingAlgorithms(int* array, int size, int searchingValue, bool search, int algorithm) {
	this->dominantOperations = 0;
	this->algorithm = algorithm;
	setArray(array, size);
	setSearchingValue(searchingValue);
	this->position = -1;
	if (search) {
		if (algorithm == 0)
			this->search(0);
		else if (algorithm == 1)
			this->search(1);
	}
};

SearchingAlgorithms::~SearchingAlgorithms() {
	delete[] this->array;
};

void SearchingAlgorithms::printArray() {
	cout << "Array:\n";
	for (int i = 0; i < this->arraySize; i++)
		cout << this->array[i] << " ";
	cout << "\n";
};

void SearchingAlgorithms::printPosition() {
	cout << "Position: " << position << "\n";
};

void SearchingAlgorithms::printDominantOperations() {
	cout << "Dominant operations: " << dominantOperations << "\n";
};

void SearchingAlgorithms::printAlgorithm() {
	cout << "Algorithm: " << getAlgorithm() << "\n";
};

int* SearchingAlgorithms::getArray() {
	return this->array;
}

int SearchingAlgorithms::getPosition() {
	return this->position;
}

unsigned long long SearchingAlgorithms::getDominantOperations() {
	return this->dominantOperations;
}

string SearchingAlgorithms::getAlgorithm() {
	if (this->algorithm == 0)
		return "linearSearch";
	else if (this->algorithm == 1)
		return "BinarySearch";
}

void SearchingAlgorithms::setArray(int* array, int size) {
	this->arraySize = size;
	this->array = new int[this->arraySize];
	for (int i = 0; i < this->arraySize; i++)
		this->array[i] = array[i];
};

void SearchingAlgorithms::setSearchingValue(int searchingValue) {
	this->searchingValue = searchingValue;
	this->position = -1;
};

void SearchingAlgorithms::search(int algorithm) {
	this->algorithm = algorithm;
	this->position = -1;
	if (this->algorithm ==0)
		this->position = linearSearch(this->array, this->searchingValue, this->arraySize);
	else if (this->algorithm == 1)
		this->position = binarySearch(this->array, this->searchingValue, 0, (this->arraySize) - 1);
}

int SearchingAlgorithms::linearSearch(int* array, int searchingValue, int size) {
	int position = -1;
	for (int i = 0; i < size; i++) {
		this->dominantOperations++;
		if (array[i] == searchingValue) {
			position = i;
			break;
		}
	}
	return position;
}

int SearchingAlgorithms::binarySearch(int* array, int searchingValue, int left, int right) {
	while (left <= right) {
		this->dominantOperations++;
		int middle = left + (right - left) / 2;
		if (array[middle] == searchingValue)
			return middle;
		if (array[middle] < searchingValue)
			left = middle + 1;
		else
			right = middle - 1;
	}
	return -1;
}