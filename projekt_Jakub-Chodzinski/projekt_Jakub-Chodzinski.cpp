#include <iostream>
#include <cstdlib>

#include "Arrays.h"

using namespace std;

void printArray(int *array, int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
}

int main()
{
    Arrays siema(10, 0, 0);
    siema.printArrays();
    cout << endl << endl;
    siema.fillArrays(100, 100);
    siema.printArrays();
    cout << endl << endl;
    int* newArr = siema.getArray(1);
    printArray(newArr, 10);
    cout << endl;
    system("pause");
}
