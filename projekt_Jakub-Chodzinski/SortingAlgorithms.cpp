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
	int i, key, j;
	for (i = 1; i < this->arraysSize; i++) {
		key = this->arrays[1][i];
		j = i - 1;
		this->dominantOperations[1]++;
		while (j >= 0 && this->arrays[1][j] > key) {
			this->dominantOperations[1]++;
			this->arrays[1][j + 1] = this->arrays[1][j];
			j = j - 1;
		}
		this->arrays[1][j + 1] = key;
	}
}

void SortingAlgorithms::merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int* L = new int[n1];
	int* R = new int[n2];
	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void SortingAlgorithms::mergeSort() {
	mergeSort2(this->arrays[2], 0, (this->arraysSize) - 1);
}

void SortingAlgorithms::mergeSort2(int arr[], int l, int r) {
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort2(arr, l, m);
		mergeSort2(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}