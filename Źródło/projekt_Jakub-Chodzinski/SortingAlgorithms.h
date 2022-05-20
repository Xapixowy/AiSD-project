#pragma once

#include <string>

class SortingAlgorithms
{
	int* array;
	int arraySize;
	unsigned long long dominantOperations;
	int algorithm;
	
	void bubbleSort(int* array, int size);
	void insertionSort(int* array, int size);
	void merge(int* array, int left, int middleValue, int right);
	void mergeSort(int* array, int left, int right);
public:
	SortingAlgorithms(int* array, int size, bool sort=true, int algorithm = 2);
	~SortingAlgorithms();
	void printArray();
	void printDominantOperations();
	void printAlgorithm();
	int* getArray();
	unsigned long long getDominantOperations();
	std::string getAlgorithm();
	void setArray(int* array, int size);
	void sort(int algorithm=2);
};

