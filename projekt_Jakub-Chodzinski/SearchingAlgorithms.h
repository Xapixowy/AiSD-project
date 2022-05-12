#pragma once

#include <string>

class SearchingAlgorithms
{
	int* array;
	int arraySize;
	int searchingValue;
	int position;
	unsigned long long dominantOperations;
	int algorithm;

	int linearSearch(int* array, int searchingValue, int size);
	int binarySearch(int* array, int searchingValue, int left, int right);
public:
	SearchingAlgorithms(int* array, int size, int searchingValue, bool search = true, int algorithm = 1);
	~SearchingAlgorithms();
	void printArray();
	void printPosition();
	void printDominantOperations();
	void printAlgorithm();
	int* getArray();
	int getPosition();
	unsigned long long getDominantOperations();
	std::string getAlgorithm();
	void setArray(int* array, int size);
	void setSearchingValue(int searchingValue);
	void search(int algorithm = 1);
};

