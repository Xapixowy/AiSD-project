#include "SortingAlgorithms.h"

#include <iostream>

using namespace std;

SortingAlgorithms::SortingAlgorithms() {
	this->arrays = nullptr;
	this->arraysSize = 0;
	for (int i = 0; i < 3; i++)
		this->dominantOperations[i] = 0;
};

SortingAlgorithms::~SortingAlgorithms() {
	for (int i = 0; i < 3; i++)
		delete[] this->arrays[i];
	delete* this->arrays;
};

SortingAlgorithms::SortingAlgorithms(int *array, int size, bool sort) {
	this->arrays = new int *[size];
	for (int i = 0; i < 3; i++) {
		this->dominantOperations[i] = 0;
	}
	setArray(array, size);
	if (sort) {
		bubbleSort();
		insertionSort();
		mergeSort();
	}
};

void SortingAlgorithms::setArray(int* array, int size) {
	this->arraysSize = size;
	for (int i = 0; i < 3; i++) {
		this->arrays[i] = new int[this->arraysSize];
		for (int j = 0; j < this->arraysSize; j++)
			this->arrays[i][j] = array[j];
	}
};

void SortingAlgorithms::printArrays() {
	cout << "Bubble Sort:" << endl;
	for (int i = 0; i < this->arraysSize; i++)
		cout << this->arrays[0][i] << " ";
	cout << endl << "Insertion Sort:" << endl;
	for (int i = 0; i < this->arraysSize; i++)
		cout << this->arrays[1][i] << " ";
	cout << endl << "Merge Sort:" << endl;
	for (int i = 0; i < this->arraysSize; i++)
		cout << this->arrays[2][i] << " ";
	cout << endl;
};

void SortingAlgorithms::printDominantOperations() {
	cout << "Bubble Sort: " << dominantOperations[0] << endl;
	cout << "Insertion Sort: " << dominantOperations[1] << endl;
	cout << "Merge Sort: " << dominantOperations[2];
	cout << endl;
};

int* SortingAlgorithms::getArray(int type) {
	if (this->arrays == nullptr)
		return nullptr;
	else {
		if (type == 0)
			return this->arrays[0];
		else if (type == 1)
			return this->arrays[1];
		else if (type == 2)
			return this->arrays[2];
		else
			return nullptr;
	}
}

int SortingAlgorithms::getDominantOperations(int type) {
	if (type == 0)
		return this->dominantOperations[0];
	else if (type == 1)
		return this->dominantOperations[1];
	else if (type == 2)
		return this->dominantOperations[2];
	else
		return -1;
}

void SortingAlgorithms::bubbleSort() {
	int temp;
	bool flag;
	for (int i = 0; i < this->arraysSize; i++) {
		flag = true;
		for (int j = 0; j < this->arraysSize - i - 1; j++) {
			this->dominantOperations[0]++;
			if (this->arrays[0][j] > this->arrays[0][j + 1]) {
				temp = this->arrays[0][j];
				this->arrays[0][j] = this->arrays[0][j + 1];
				this->arrays[0][j + 1] = temp;
				flag = false;
			}
		}
		if (flag)
			break;
	}
}

void SortingAlgorithms::insertionSort() {
	int dominantOperations[2] = { 0,0 };
	bool flag;
	int i, key, j;
	for (i = 1; i < this->arraysSize; i++) {
		flag = false;
		key = this->arrays[1][i];
		j = i - 1;
		dominantOperations[0]++;
		while (j >= 0 && this->arrays[1][j] > key) {
			flag = true;
			dominantOperations[1]++;
			this->arrays[1][j + 1] = this->arrays[1][j];
			j = j - 1;
		}
		if (flag)
			dominantOperations[1]--;
		this->arrays[1][j + 1] = key;
	}
	this->dominantOperations[1] = dominantOperations[0] + dominantOperations[1];
}

void SortingAlgorithms::merge(int* array, int left, int middleValue, int right) {
	this->dominantOperations[2]++;
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
		array[k] = Left[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		array[k] = Right[j];
		j++;
		k++;
	}
}

void SortingAlgorithms::mergeSort() {
	mergeSort2(this->arrays[2], 0, (this->arraysSize) - 1);
}

void SortingAlgorithms::mergeSort2(int* array, int left, int right) {
	if (left < right)
	{
		int middleValue = left + (right - left) / 2;
		mergeSort2(array, left, middleValue);
		mergeSort2(array, middleValue + 1, right);
		merge(array, left, middleValue, right);
	}
}