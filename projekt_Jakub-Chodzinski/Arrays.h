#pragma once

class Arrays
{
	int size, max, min;
	int* randomArray;
	int* ascendingArray;
	int* descendingArray;
public:
	Arrays(int size, int max=100, int min=0);
	~Arrays();
	void fillArrays(int size, int max=100, int min=0);
	int* getArray(int type);
	void printArrays();
};

