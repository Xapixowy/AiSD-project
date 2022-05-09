#pragma once
class SortingAlgorithms
{
	int** arrays;
	int arraysSize;
	int dominantOperations[3];
	void merge(int array[], int l, int m, int r);
	void mergeSort2(int array[], int l, int r);
public:
	SortingAlgorithms();
	SortingAlgorithms(int array[], int size, bool sort=true);
	~SortingAlgorithms();
	void setArray(int* array, int size);
	void printArrays();
	void printDominantOperations();
	int* getArray(int type);
	int getDominantOperations(int type);
	void bubbleSort();
	void insertionSort();
	void mergeSort();
};

