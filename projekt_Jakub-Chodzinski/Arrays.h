#pragma once

class Arrays
{
	int n, max, min;
	int* randomArray;
	int* ascendingArray;
	int* descendingArray;
public:
	int size;
	Arrays();
	Arrays(int n, int max=100, int min=0);
	~Arrays();
	void fillArrays(int max=100, int min=0);
	int* getArray(int type);
	void printArrays();
};

