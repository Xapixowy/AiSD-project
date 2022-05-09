#pragma once
class SearchingAlgorithms
{
	int* array;
	int arraySize;
	int searchingValue;
	int positions[2];
	int dominantOperations[2];
	int binarySearch2(int* array, int searchingValue, int start, int end);
public:
	SearchingAlgorithms(int* array, int size, int searchingValue, bool search = true);
	~SearchingAlgorithms();
	void printArray();
	void printPositions();
	void printDominantOperations();
	int* getArray();
	int getPositions(int type);
	int getDominantOperations(int type);
	void setArray(int* array, int size);
	void setSearchingValue(int searchingValue);
	void linearSearch();
	void binarySearch();
};

