#include <iostream>
#include <cstdlib>

#include "Arrays.h"
#include "SortingAlgorithms.h"
#include "SearchingAlgorithms.h"

using namespace std;

int main()
{
    const int dataSize = 10;

    Arrays arr(dataSize, dataSize);
    arr.printArrays();

    cout << endl << "--------------------" << endl << endl;

    cout << "Array of random values:" << endl;
    SortingAlgorithms randomArray(arr.getArray(0), dataSize);
    randomArray.printDominantOperations();

    cout << endl << "-----" << endl << endl;

    cout << "Array of ascending values:" << endl;
    SortingAlgorithms ascendingArray(arr.getArray(1), dataSize);
    ascendingArray.printDominantOperations();

    cout << endl << "-----" << endl << endl;

    cout << "Array of descending values:" << endl;
    SortingAlgorithms descendingArray(arr.getArray(2), dataSize);
    descendingArray.printDominantOperations();

    cout << endl << "--------------------" << endl << endl;
    SearchingAlgorithms newSearch(arr.getArray(1), dataSize, 1, false);
    int tablica[10] = { 1,2,3,4,5,6,7,8,9,10 };
    newSearch.setArray(tablica, 10);
    newSearch.printArray();
    newSearch.printPositions();
    newSearch.linearSearch();
    newSearch.binarySearch();
    cout << endl;
    newSearch.printPositions();
    newSearch.printDominantOperations();

    system("pause");
}
