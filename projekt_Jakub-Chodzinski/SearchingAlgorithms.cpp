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
	cout << (char)(175) << " Array:" << endl;
	for (int i = 0; i < this->arraySize; i++)
		cout << this->array[i] << " ";
	cout << endl;
};

void SearchingAlgorithms::printPositions() {
	cout << (char)(175) << " Positions of searching value:" << endl;
	cout << "Linear Search: " << positions[0] << endl;
	cout << "Binary Search: " << positions[1] << endl;
	cout << endl;
};

void SearchingAlgorithms::printDominantOperations() {
	cout << (char)(175) << " Dominant operations:" << endl;
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