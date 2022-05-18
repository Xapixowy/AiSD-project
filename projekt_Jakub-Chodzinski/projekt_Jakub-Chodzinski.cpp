#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cmath>
#include <ctime>

#include "Arrays.h"
#include "SortingAlgorithms.h"
#include "SearchingAlgorithms.h"

using namespace std;

int main()
{
    // Tryb debugowania
    // debug = true <-- Wlacza tryb debugowania
    // debug = false <-- Wylacza tryb debugowania
    bool debug = false;

    // Obsluga programu
    cout << "AiSD - Projekt\n\n";
    fstream data;
    string fileName = "", folderName="data";
    bool runDefaultProgram = true;
    int dataQuantity = 0, dataSize = 0, dataMin = 0, dataMax = 0, searchingValue = 0;
    char dataMaxAuto = 'a', bubbleSort = 'a', insertionSort = 'a', mergeSort = 'a',linearSearch = 'a', binarySearch = 'a', searchingValueAuto = 'a', saveToFile = 'a', showData = 'a';
    if (debug) {
        runDefaultProgram = true;
        dataQuantity = 100;
        dataSize = 10;
        dataMaxAuto = 'y';
        dataMin = 1;
        dataMax = 100;
        bubbleSort = 'y';
        insertionSort = 'y';
        mergeSort = 'y';
        linearSearch = 'y';
        binarySearch = 'y';
        searchingValueAuto = 'y';
        searchingValue = 319;
        saveToFile = 'y';
        fileName = "data";
        showData = 'n';
    }
    else {
        cout << "Podaj liczbe tablic do wygenerowania (>0): ";
        while (dataQuantity <= 0)
            cin >> dataQuantity;
        cout << "Podaj liczbe elementow pierwszej tablicy (>0): ";
        while (dataSize <= 0)
            cin >> dataSize;
        cout << "Czy chcesz, aby maksymalna wartosc elementu w tablicy byla proporcjonalna do jej dlugosci? (y/n): ";
        while (!cin.fail() && tolower(dataMaxAuto) != 'y' && tolower(dataMaxAuto) != 'n')
            cin >> dataMaxAuto;
        if (dataMaxAuto == 'n') {
            cout << "Podaj maksymalna wartosc elementu w tablicy: ";
            cin >> dataMax;
            cout << "Podaj minimalna wartosc elementu w tablicy (<max): ";
            do
                cin >> dataMin;
            while (dataMin >= dataMax);
        }
        else {
            dataMin = 0;
            dataMax = 0;
        }
        cout << "\nCzy chcesz uzyc algorytmu sortowania babelkowego? (y/n): ";
        while (!cin.fail() && tolower(bubbleSort) != 'y' && tolower(bubbleSort) != 'n')
            cin >> bubbleSort;
        cout << "Czy chcesz uzyc algorytmu sortowania przez wstawianie? (y/n): ";
        while (!cin.fail() && tolower(insertionSort) != 'y' && tolower(insertionSort) != 'n')
            cin >> insertionSort;
        cout << "Czy chcesz uzyc algorytmu sortowania przez scalanie? (y/n): ";
        while (!cin.fail() && tolower(mergeSort) != 'y' && tolower(mergeSort) != 'n')
            cin >> mergeSort;
        cout << "Czy chcesz uzyc algorytmu wyszukiwania liniowego? (y/n): ";
        while (!cin.fail() && tolower(linearSearch) != 'y' && tolower(linearSearch) != 'n')
            cin >> linearSearch;
        cout << "Czy chcesz uzyc algorytmu wyszukiwania biarnego? (y/n): ";
        while (!cin.fail() && tolower(binarySearch) != 'y' && tolower(binarySearch) != 'n')
            cin >> binarySearch;
        if (linearSearch == 'y' || binarySearch == 'y') {
            cout << "\nCzy chcesz, aby wyszukiwana wartoscia dla algorytmow wyszukiwania byla losowa wartoscia? (y/n): ";
            while (!cin.fail() && tolower(searchingValueAuto) != 'y' && tolower(searchingValueAuto) != 'n')
                cin >> searchingValueAuto;
            if (searchingValueAuto == 'n') {
                cout << "Podaj wyszukiwana wartosc dla algorytmow wyszukiwania (>=min i <=max): ";
                do
                    cin >> searchingValue;
                while (searchingValue < dataMin || searchingValue > dataMax);
            }
        }
        cout << "\nZapisac wynik dzialania programu do pliku (y/n)?: ";
        while (!cin.fail() && tolower(saveToFile) != 'y' && tolower(saveToFile) != 'n')
            cin >> saveToFile;
        if (saveToFile == 'y') {
            cout << "Podaj nazwe pliku (bez rozszerzenia): ";
            while (!cin.fail() && fileName.size() < 3)
                cin >> fileName;
        }
        cout << "\nWyswietlic dane (y/n)?: ";
        while (!cin.fail() && tolower(showData) != 'y' && tolower(showData) != 'n')
            cin >> showData;
    }

    if (runDefaultProgram) {
        // Wyswietlenie podsumowania wyborow uzytkownika
        system("cls");
        cout << (char)(175) << " Podsumowanie wyborow:\n";
        cout << "Liczba tablic do wygenerowania: " << dataQuantity << "\n";
        cout << "Liczba elementow pierwszej tablicy: " << dataSize << "\n";
        cout << "Minimalna wartosc elementu w tablicy: ";
        if (dataMaxAuto == 'y')
            cout << "1\n";
        else
            cout << dataMin << "\n";
        cout << "Maksymalna wartosc elementu w tablicy: ";
        if (dataMaxAuto == 'y')
            cout << "auto\n";
        else
            cout << dataMax << "\n";
        if (linearSearch == 'y' || binarySearch == 'y') {
            cout << "Wyszukiwana wartosc dla algorytmow wyszukiwania: ";
            if (searchingValueAuto == 'y')
                cout << "auto\n";
            else
                cout << searchingValue << "\n";
        }
        cout << "Czy zapisac dane do pliku: " << (saveToFile == 'y' ? "tak" : "nie") << "\n";
        if (saveToFile == 'y') {
            cout << "Nazwa pliku: " << fileName << "\n";
        }
        cout << "Czy wyswietlic dane: " << (showData == 'y' ? "tak" : "nie") << "\n\n";
        cout << "=======================================================\n\n";

        // Tworzenie obiektow
        if ((bubbleSort == 'y') || (insertionSort == 'y') || (mergeSort == 'y') || (linearSearch == 'y') || (binarySearch == 'y')) {
            srand(time(NULL));
            cout << "[ ] Tworzenie obiektow...";
            Arrays** tablice = new Arrays * [dataQuantity];
            SortingAlgorithms** bubbleSortRandom = new SortingAlgorithms * [dataQuantity - 1];
            SortingAlgorithms** bubbleSortAscending = new SortingAlgorithms * [dataQuantity - 1];
            SortingAlgorithms** bubbleSortDescending = new SortingAlgorithms * [dataQuantity - 1];
            SortingAlgorithms** insertionSortRandom = new SortingAlgorithms * [dataQuantity - 1];
            SortingAlgorithms** insertionSortAscending = new SortingAlgorithms * [dataQuantity - 1];
            SortingAlgorithms** insertionSortDescending = new SortingAlgorithms * [dataQuantity - 1];
            SortingAlgorithms** mergeSortRandom = new SortingAlgorithms * [dataQuantity - 1];
            SortingAlgorithms** mergeSortAscending = new SortingAlgorithms * [dataQuantity - 1];
            SortingAlgorithms** mergeSortDescending = new SortingAlgorithms * [dataQuantity - 1];
            SearchingAlgorithms** linearSearchRandom = new SearchingAlgorithms * [dataQuantity - 1];
            SearchingAlgorithms** linearSearchAscending = new SearchingAlgorithms * [dataQuantity - 1];
            SearchingAlgorithms** linearSearchDescending = new SearchingAlgorithms * [dataQuantity - 1];
            SearchingAlgorithms** binarySearchAscending = new SearchingAlgorithms * [dataQuantity - 1];
            for (int i = 0; i < dataQuantity-1; i++) {
                if (searchingValueAuto == 'y')
                    searchingValue = rand() % ((i + 1) * dataSize) + 1;
                tablice[i] = new Arrays((i + 1) * dataSize, dataMax, dataMin);
                if (bubbleSort == 'y') {
                    bubbleSortRandom[i] = new SortingAlgorithms(tablice[i]->getArray(0), (i + 1) * dataSize, false);
                    bubbleSortAscending[i] = new SortingAlgorithms(tablice[i]->getArray(1), (i + 1) * dataSize, false);
                    bubbleSortDescending[i] = new SortingAlgorithms(tablice[i]->getArray(2), (i + 1) * dataSize, false);
                }
                if (insertionSort == 'y') {
                    insertionSortRandom[i] = new SortingAlgorithms(tablice[i]->getArray(0), (i + 1) * dataSize, false);
                    insertionSortAscending[i] = new SortingAlgorithms(tablice[i]->getArray(1), (i + 1) * dataSize, false);
                    insertionSortDescending[i] = new SortingAlgorithms(tablice[i]->getArray(2), (i + 1) * dataSize, false);
                }
                if (mergeSort == 'y') {
                    mergeSortRandom[i] = new SortingAlgorithms(tablice[i]->getArray(0), (i + 1) * dataSize, false);
                    mergeSortAscending[i] = new SortingAlgorithms(tablice[i]->getArray(1), (i + 1) * dataSize, false);
                    mergeSortDescending[i] = new SortingAlgorithms(tablice[i]->getArray(2), (i + 1) * dataSize, false);
                }
                if (linearSearch == 'y') {
                    linearSearchRandom[i] = new SearchingAlgorithms(tablice[i]->getArray(0), (i + 1) * dataSize, searchingValue,false);
                    linearSearchAscending[i] = new SearchingAlgorithms(tablice[i]->getArray(1), (i + 1) * dataSize, searchingValue, false);
                    linearSearchDescending[i] = new SearchingAlgorithms(tablice[i]->getArray(2), (i + 1) * dataSize, searchingValue, false);
                }
                if (binarySearch == 'y') {
                    binarySearchAscending[i] = new SearchingAlgorithms(tablice[i]->getArray(1), (i + 1) * dataSize, searchingValue, false);
                }
                tablice[i]->~Arrays();
            }
            cout << "\r[X] Obiekty stworzone!   \n";

            // Sortowanie obiektow
            if (bubbleSort == 'y' || insertionSort == 'y' || mergeSort == 'y') {
                cout << "Sortowanie obiektow...\n";
                if (bubbleSort == 'y') {
                    cout << "\t[ ] Algorytm sortowania babelkowego...";
                    for (int i = 0; i < dataQuantity - 1; i++) {
                        bubbleSortRandom[i]->sort(0);
                        bubbleSortAscending[i]->sort(0);
                        bubbleSortDescending[i]->sort(0);
                    }
                    cout << "\r\t[X] Algorytm sortowania babelkowego   \n";
                }
                if (insertionSort == 'y') {
                    cout << "\t[ ] Algorytm sortowania przez wstawianie...";
                    for (int i = 0; i < dataQuantity - 1; i++) {
                        insertionSortRandom[i]->sort(1);
                        insertionSortAscending[i]->sort(1);
                        insertionSortDescending[i]->sort(1);
                    }
                    cout << "\r\t[X] Algorytm sortowania przez wstawianie   \n";
                }
                if (mergeSort == 'y') {
                    cout << "\t[ ] Algorytm sortowania przez scalanie...";
                    for (int i = 0; i < dataQuantity - 1; i++) {
                        mergeSortRandom[i]->sort(2);
                        mergeSortAscending[i]->sort(2);
                        mergeSortDescending[i]->sort(2);
                    }
                    cout << "\r\t[X] Algorytm sortowania przez scalanie   \n";
                }
            }

            // Przeszukiwanie obiektow
            if (linearSearch == 'y' || binarySearch == 'y') {
                cout << "Przeszukiwanie obiektow...\n";
                if (linearSearch == 'y') {
                    cout << "\t[ ] Algorytm wyszukiwania liniowego...";
                    for (int i = 0; i < dataQuantity - 1; i++) {
                        linearSearchRandom[i]->search(0);
                        linearSearchAscending[i]->search(0);
                        linearSearchDescending[i]->search(0);
                    }
                    cout << "\r\t[X] Algorytm wyszukiwania liniowego   \n";
                }
                if (binarySearch == 'y') {
                    cout << "\t[ ] Algorytm wyszukiwania binarnego...";
                    for (int i = 0; i < dataQuantity - 1; i++) {
                        binarySearchAscending[i]->search(1);
                    }
                    cout << "\r\t[X] Algorytm wyszukiwania binarnego   \n";
                }
            }

            // Zapis danych do pliku
            if (saveToFile == 'y') {
                cout << "[ ] Zapisywanie danych do pliku...";
                fileName.append(".txt");
                if (folderName.size() == 0)
                    folderName = fileName;
                else {
                    folderName.append("/");
                    folderName.append(fileName);
                }
                data.open(folderName, ios::app);
                data << "Algorytm;Wielkosc tablicy;Wartosci losowo;Wartosci rosnaco;Wartosci malejaco;Pomocnicza\n";
                data << "sortowanie babelkowe;0;0;0;0;0\n";
                for (int i = 0; i < dataQuantity - 1; i++) {
                    data << "sortowanie babelkowe;";
                    data << (i + 1) * dataSize << ";";
                    if (bubbleSort == 'y') {
                        data << bubbleSortRandom[i]->getDominantOperations() << ";";
                        data << bubbleSortAscending[i]->getDominantOperations() << ";";
                        data << bubbleSortDescending[i]->getDominantOperations() << ";";
                        data << pow((i + 1) * dataSize, 2) << "\n";
                    }
                    else
                        data << "0;0;0;0\n";
                }
                data << "sortowanie przez wstawianie;0;0;0;0;0\n";
                for (int i = 0; i < dataQuantity - 1; i++) {
                    data << "sortowanie przez wstawianie;";
                    data << (i + 1) * dataSize << ";";
                    if (insertionSort == 'y') {
                        data << insertionSortRandom[i]->getDominantOperations() << ";";
                        data << insertionSortAscending[i]->getDominantOperations() << ";";
                        data << insertionSortDescending[i]->getDominantOperations() << ";";
                        data << pow((i + 1) * dataSize, 2) << "\n";
                    }
                    else
                        data << "0;0;0;0\n";
                }
                data << "sortowanie przez scalanie;0;0;0;0;0\n";
                for (int i = 0; i < dataQuantity - 1; i++) {
                    data << "sortowanie przez scalanie;";
                    data << (i + 1) * dataSize << ";";
                    if (mergeSort == 'y') {
                        data << mergeSortRandom[i]->getDominantOperations() << ";";
                        data << mergeSortAscending[i]->getDominantOperations() << ";";
                        data << mergeSortDescending[i]->getDominantOperations() << ";";
                        data << ((i + 1) * dataSize) * log2((i + 1) * dataSize) << "\n";
                    }
                    else
                        data << "0;0;0;0\n";
                }
                data << "wyszukiwanie liniowe;0;0;0;0;0\n";
                for (int i = 0; i < dataQuantity - 1; i++) {
                    data << "wyszukiwanie liniowe;";
                    data << (i + 1) * dataSize << ";";
                    if (linearSearch == 'y') {
                        data << linearSearchRandom[i]->getDominantOperations() << ";";
                        data << linearSearchAscending[i]->getDominantOperations() << ";";
                        data << linearSearchDescending[i]->getDominantOperations() << ";";
                        data << (i + 1) * dataSize << "\n";
                    }
                    else
                        data << "0;0;0;0\n";
                }
                data << "wyszukiwanie binarne;0;0;0;0;0\n";
                for (int i = 0; i < dataQuantity - 1; i++) {
                    data << "wyszukiwanie binarne;";
                    data << (i + 1) * dataSize << ";";
                    if (binarySearch == 'y') {
                        data << "0;";
                        data << binarySearchAscending[i]->getDominantOperations() << ";";
                        data << "0;";
                        data << log2((i + 1) * dataSize) << "\n";
                    }
                    else
                        data << "0;0;0;0\n";
                }
                data.close();
                cout << "\r[X] Dane zapisane do pliku!       \n";
            }

            cout << "\n=======================================================\n\n";

            // Wyswietlanie danych
            if (showData == 'y') {
                if (bubbleSort == 'y') {
                    cout << "\n" << (char)(175) << " Sortowanie babelkowe:\n";
                    cout << "------------------------------------------------------------\n";
                    cout << setw(12) << "Wielkosc\t";
                    cout << setw(12) << "Wartosci\t";
                    cout << setw(12) << "Wartosci\t";
                    cout << setw(12) << "Wartosci\n";
                    cout << setw(12) << "tablicy:\t";
                    cout << setw(12) << "losowo:\t";
                    cout << setw(12) << "rosnaco:\t";
                    cout << setw(12) << "malejaco:\n";
                    cout << "------------------------------------------------------------\n";
                    cout << setw(12) << "0\t";
                    cout << setw(12) << "0\t";
                    cout << setw(12) << "0\t";
                    cout << setw(12) << "0\n";
                    for (int i = 0; i < dataQuantity - 1; i++) {
                        cout << setw(12) << (i + 1) * dataSize << "\t";
                        cout << setw(12) << bubbleSortRandom[i]->getDominantOperations() << "\t";
                        cout << setw(12) << bubbleSortAscending[i]->getDominantOperations() << "\t";
                        cout << setw(12) << bubbleSortDescending[i]->getDominantOperations() << "\n";
                    }
                }
                if (insertionSort == 'y') {
                    cout << "\n" << (char)(175) << " Sortowanie przez wstawianie:\n";
                    cout << "------------------------------------------------------------\n";
                    cout << setw(12) << "Wielkosc\t";
                    cout << setw(12) << "Wartosci\t";
                    cout << setw(12) << "Wartosci\t";
                    cout << setw(12) << "Wartosci\n";
                    cout << setw(12) << "tablicy:\t";
                    cout << setw(12) << "losowo:\t";
                    cout << setw(12) << "rosnaco:\t";
                    cout << setw(12) << "malejaco:\n";
                    cout << "------------------------------------------------------------\n";
                    cout << setw(12) << "0\t";
                    cout << setw(12) << "0\t";
                    cout << setw(12) << "0\t";
                    cout << setw(12) << "0\n";
                    for (int i = 0; i < dataQuantity - 1; i++) {
                        cout << setw(12) << (i + 1) * dataSize << "\t";
                        cout << setw(12) << insertionSortRandom[i]->getDominantOperations() << "\t";
                        cout << setw(12) << insertionSortAscending[i]->getDominantOperations() << "\t";
                        cout << setw(12) << insertionSortDescending[i]->getDominantOperations() << "\n";
                    }
                }
                if (mergeSort == 'y') {
                    cout << "\n" << (char)(175) << " Sortowanie przez scalanie:\n";
                    cout << "------------------------------------------------------------\n";
                    cout << setw(12) << "Wielkosc\t";
                    cout << setw(12) << "Wartosci\t";
                    cout << setw(12) << "Wartosci\t";
                    cout << setw(12) << "Wartosci\n";
                    cout << setw(12) << "tablicy:\t";
                    cout << setw(12) << "losowo:\t";
                    cout << setw(12) << "rosnaco:\t";
                    cout << setw(12) << "malejaco:\n";
                    cout << "------------------------------------------------------------\n";
                    cout << setw(12) << "0\t";
                    cout << setw(12) << "0\t";
                    cout << setw(12) << "0\t";
                    cout << setw(12) << "0\n";
                    for (int i = 0; i < dataQuantity - 1; i++) {
                        cout << setw(12) << (i + 1) * dataSize << "\t";
                        cout << setw(12) << mergeSortRandom[i]->getDominantOperations() << "\t";
                        cout << setw(12) << mergeSortAscending[i]->getDominantOperations() << "\t";
                        cout << setw(12) << mergeSortDescending[i]->getDominantOperations() << "\n";
                    }
                }
                if (linearSearch == 'y') {
                    cout << "\n" << (char)(175) << " Wyszukiwanie liniowe:\n";
                    cout << "------------------------------------------------------------\n";
                    cout << setw(12) << "Wielkosc\t";
                    cout << setw(12) << "Wartosci\t";
                    cout << setw(12) << "Wartosci\t";
                    cout << setw(12) << "Wartosci\n";
                    cout << setw(12) << "tablicy:\t";
                    cout << setw(12) << "losowo:\t";
                    cout << setw(12) << "rosnaco:\t";
                    cout << setw(12) << "malejaco:\n";
                    cout << "------------------------------------------------------------\n";
                    cout << setw(12) << "0\t";
                    cout << setw(12) << "0\t";
                    cout << setw(12) << "0\t";
                    cout << setw(12) << "0\n";
                    for (int i = 0; i < dataQuantity - 1; i++) {
                        cout << setw(12) << (i + 1) * dataSize << "\t";
                        cout << setw(12) << linearSearchRandom[i]->getDominantOperations() << "\t";
                        cout << setw(12) << linearSearchAscending[i]->getDominantOperations() << "\t";
                        cout << setw(12) << linearSearchDescending[i]->getDominantOperations() << "\n";
                    }
                }
                if (binarySearch == 'y') {
                    cout << "\n" << (char)(175) << " Wyszukiwanie binarne:\n";
                    cout << "------------------------------------------------------------\n";
                    cout << setw(12) << "Wielkosc\t";
                    cout << setw(12) << "Wartosci\t";
                    cout << setw(12) << "Wartosci\t";
                    cout << setw(12) << "Wartosci\n";
                    cout << setw(12) << "tablicy:\t";
                    cout << setw(12) << "losowo:\t";
                    cout << setw(12) << "rosnaco:\t";
                    cout << setw(12) << "malejaco:\n";
                    cout << "------------------------------------------------------------\n";
                    cout << setw(12) << "0\t";
                    cout << setw(12) << "-\t";
                    cout << setw(12) << "0\t";
                    cout << setw(12) << "-\n";
                    for (int i = 0; i < dataQuantity - 1; i++) {
                        cout << setw(12) << (i + 1) * dataSize << "\t";
                        cout << setw(12) << "-\t";
                        cout << setw(12) << binarySearchAscending[i]->getDominantOperations() << "\t";
                        cout << setw(12) << "-\n";
                    }
                }
            }
        }
    }
    else {
        // Kod do przetestowania 
    }
    system("pause");
}
