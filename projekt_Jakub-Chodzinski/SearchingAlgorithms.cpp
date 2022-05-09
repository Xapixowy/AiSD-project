#include "SearchingAlgorithms.h"

#include <iostream>

using namespace std;

SearchingAlgorithms::SearchingAlgorithms(int* array, int size, int searchingValue, bool search) {
	setArray(array, size);
	setSearchingValue(searchingValue);
	for (int i = 0; i < 2; i++) {
		this->dominantOperations[i] = 0;
	}
	if (search) {
		linearSearch();
		binarySearch();
	}
};

SearchingAlgorithms::~SearchingAlgorithms() {
	delete this->array;
};

int* SearchingAlgorithms::getArray() {
	return this->array;
}

int SearchingAlgorithms::getPositions(int type) {
	if (type == 0)
		return this->positions[0];
	else if (type == 1)
		return this->positions[1];
	else
		return -1;
}

int SearchingAlgorithms::getDominantOperations(int type) {
	if (type == 0)
		return this->dominantOperations[0];
	else if (type == 1)
		return this->dominantOperations[1];
	else
		return -1;
}


void SearchingAlgorithms::setArray(int* array, int size) {
	this->array = array;
	this->arraySize = size;
};

void SearchingAlgorithms::setSearchingValue(int searchingValue) {
	this->searchingValue = searchingValue;
	for (int i = 0; i < 2; i++) {
		this->positions[i] = -1;
	}
};

void SearchingAlgorithms::printArray() {
	for (int i = 0; i < this->arraySize; i++)
		cout << this->array[i] << " ";
	cout << endl;
};

void SearchingAlgorithms::printPositions() {
	cout << "Linear Search: " << positions[0] << endl;
	cout << "Binary Search: " << positions[1] << endl;
	cout << endl;
};

void SearchingAlgorithms::printDominantOperations() {
	cout << "Linear Search: " << dominantOperations[0] << endl;
	cout << "Binary Search: " << dominantOperations[1] << endl;
	cout << endl;
};

void SearchingAlgorithms::linearSearch() {
	for (int i = 0; i < this->arraySize; i++) {
		this->dominantOperations[0]++;
		if (this->array[i] == this->searchingValue) {
			this->positions[0] = i;
			break;
		}
	}
}

void SearchingAlgorithms::binarySearch() {
	this->positions[1] = binarySearch2(this->array, this->searchingValue, 0, (this->arraySize)-1);
}

int SearchingAlgorithms::binarySearch2(int* array, int searchingValue, int start, int end) {
	if (end >= start) {
		this->dominantOperations[1]++;
		int middleValue = (start + end) / 2;
		if (array[middleValue] == searchingValue)
			return middleValue;
		else {
			if (array[middleValue] > searchingValue)
				return binarySearch2(array, searchingValue, start, middleValue - 1);
			else
				return binarySearch2(array, searchingValue, middleValue + 1, end);
		}
	}
	return -1;
}