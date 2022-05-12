#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>

#include "Arrays.h"
#include "SortingAlgorithms.h"
#include "SearchingAlgorithms.h"

using namespace std;

int main()
{
    // Tryb debugowania
    // debug = true <-- Wlacza tryb debugowania
    // debug = false <-- Wylacza tryb debugowania
    bool debug = true;

    // Obsluga programu
    setw(16);
    cout << "AiSD - Projekt\n\n";
    fstream data;
    string fileName = "", folderName="data";
    bool createObjects = true;
    int dataQuantity = 0, dataSize = 0, dataMin, dataMax, searchingValue;
    char saveToFile = 'a', showData = 'a', bubbleSort='a', insertionSort ='a', mergeSort='a', linearSearch='a', binarySearch='a';
    if (debug) {
        createObjects = true;
        dataQuantity = 100;
        dataSize = 500;
        dataMin = 0;
        dataMax = 0;
        bubbleSort = 'y';
        insertionSort = 'y';
        mergeSort = 'y';
        linearSearch = 'y';
        binarySearch = 'y';
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
        cout << "Podaj maksymalna wartosc elementu w tablicy: ";
        cin >> dataMax;
        cout << "Podaj minimalna wartosc elementu w tablicy (<max): ";
        do
            cin >> dataMin;
        while (dataMin > dataMax);
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
            cout << "\nPodaj wyszukiwana wartosc dla algorytmow wyszukiwania (>=min i <=max): ";
            do
                cin >> searchingValue;
            while (searchingValue < dataMin || searchingValue > dataMax);
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

    if (createObjects) {
        // Wyswietlenie podsumowania wyborow uzytkownika
        system("cls");
        cout << (char)(175) << " Podsumowanie wyborow:\n";
        cout << "Liczba tablic do wygenerowania: " << dataQuantity << "\n";
        cout << "Liczba elementow pierwszej tablicy: " << dataSize << "\n";
        cout << "Minimalna wartosc elementu w tablicy: " << dataMin << "\n";
        cout << "Maksymalna wartosc elementu w tablicy: " << dataMax << "\n";
        cout << "Wyszukiwana wartosc dla algorytmow wyszukiwania: " << searchingValue << "\n";
        cout << "Czy zapisac dane do pliku: " << (saveToFile == 'y' ? "tak" : "nie") << "\n";
        if (saveToFile == 'y') {
            cout << "Nazwa pliku: " << fileName << "\n";
        }
        cout << "Czy wyswietlic dane: " << (showData == 'y' ? "tak" : "nie") << "\n\n";
        cout << "=======================================================\n\n";

        // Tworzenie obiektow
        if ((bubbleSort == 'y') || (insertionSort == 'y') || (mergeSort == 'y') || (linearSearch == 'y') || (binarySearch == 'y')) {
            cout << "[ ] Tworzenie obiektow...";
            Arrays** tablice = new Arrays * [dataQuantity];
            SortingAlgorithms** bubbleSortRandom = new SortingAlgorithms * [dataQuantity];
            SortingAlgorithms** bubbleSortAscending = new SortingAlgorithms * [dataQuantity];
            SortingAlgorithms** bubbleSortDescending = new SortingAlgorithms * [dataQuantity];
            SortingAlgorithms** insertionSortRandom = new SortingAlgorithms * [dataQuantity];
            SortingAlgorithms** insertionSortAscending = new SortingAlgorithms * [dataQuantity];
            SortingAlgorithms** insertionSortDescending = new SortingAlgorithms * [dataQuantity];
            SortingAlgorithms** mergeSortRandom = new SortingAlgorithms * [dataQuantity];
            SortingAlgorithms** mergeSortAscending = new SortingAlgorithms * [dataQuantity];
            SortingAlgorithms** mergeSortDescending = new SortingAlgorithms * [dataQuantity];
            SearchingAlgorithms** linearSearchRandom = new SearchingAlgorithms * [dataQuantity];
            SearchingAlgorithms** linearSearchAscending = new SearchingAlgorithms * [dataQuantity];
            SearchingAlgorithms** linearSearchDescending = new SearchingAlgorithms * [dataQuantity];
            SearchingAlgorithms** binarySearchAscending = new SearchingAlgorithms * [dataQuantity];
            for (int i = 0; i < dataQuantity; i++) {
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
                    for (int i = 0; i < dataQuantity; i++) {
                        bubbleSortRandom[i]->sort(0);
                        bubbleSortAscending[i]->sort(0);
                        bubbleSortDescending[i]->sort(0);
                    }
                    cout << "\r\t[X] Algorytm sortowania babelkowego   \n";
                }
                if (insertionSort == 'y') {
                    cout << "\t[ ] Algorytm sortowania przez wstawianie...";
                    for (int i = 0; i < dataQuantity; i++) {
                        insertionSortRandom[i]->sort(1);
                        insertionSortAscending[i]->sort(1);
                        insertionSortDescending[i]->sort(1);
                    }
                    cout << "\r\t[X] Algorytm sortowania przez wstawianie   \n";
                }
                if (mergeSort == 'y') {
                    cout << "\t[ ] Algorytm sortowania przez scalanie...";
                    for (int i = 0; i < dataQuantity; i++) {
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
                    for (int i = 0; i < dataQuantity; i++) {
                        linearSearchRandom[i]->search(0);
                        linearSearchAscending[i]->search(0);
                        linearSearchDescending[i]->search(0);
                    }
                    cout << "\r\t[X] Algorytm wyszukiwania liniowego   \n";
                }
                if (binarySearch == 'y') {
                    cout << "\t[ ] Algorytm wyszukiwania binarnego...";
                    for (int i = 0; i < dataQuantity; i++) {
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
                data << "Algorytm;Wielkosc tablicy;Wartosci losowo;Wartosci rosnaco;Wartosci malejaco\n";
                for (int i = 0; i < dataQuantity; i++) {
                    data << "sortowanie babelkowe;";
                    data << (i + 1) * dataSize << ";";
                    if (bubbleSort == 'y') {
                        data << bubbleSortRandom[i]->getDominantOperations() << ";";
                        data << bubbleSortAscending[i]->getDominantOperations() << ";";
                        data << bubbleSortDescending[i]->getDominantOperations() << "\n";
                    }
                    else
                        data << "0;0;0\n";
                }
                for (int i = 0; i < dataQuantity; i++) {
                    data << "sortowanie przez wstawianie;";
                    data << (i + 1) * dataSize << ";";
                    if (insertionSort == 'y') {
                        data << insertionSortRandom[i]->getDominantOperations() << ";";
                        data << insertionSortAscending[i]->getDominantOperations() << ";";
                        data << insertionSortDescending[i]->getDominantOperations() << "\n";
                    }
                    else
                        data << "0;0;0\n";
                }
                for (int i = 0; i < dataQuantity; i++) {
                    data << "sortowanie przez scalanie;";
                    data << (i + 1) * dataSize << ";";
                    if (mergeSort == 'y') {
                        data << mergeSortRandom[i]->getDominantOperations() << ";";
                        data << mergeSortAscending[i]->getDominantOperations() << ";";
                        data << mergeSortDescending[i]->getDominantOperations() << "\n";
                    }
                    else
                        data << "0;0;0\n";
                }
                for (int i = 0; i < dataQuantity; i++) {
                    data << "wyszukiwanie liniowe;";
                    data << (i + 1) * dataSize << ";";
                    if (linearSearch == 'y') {
                        data << linearSearchRandom[i]->getDominantOperations() << ";";
                        data << linearSearchAscending[i]->getDominantOperations() << ";";
                        data << linearSearchDescending[i]->getDominantOperations() << "\n";
                    }
                    else
                        data << "0;0;0\n";
                }
                for (int i = 0; i < dataQuantity; i++) {
                    data << "wyszukiwanie binarne;";
                    data << (i + 1) * dataSize << ";";
                    if (binarySearch == 'y') {
                        data << "-;";
                        data << binarySearchAscending[i]->getDominantOperations() << ";";
                        data << "-;\n";
                    }
                    else
                        data << "-;0;-\n";
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
                    for (int i = 0; i < dataQuantity; i++) {
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
                    for (int i = 0; i < dataQuantity; i++) {
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
                    for (int i = 0; i < dataQuantity; i++) {
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
                    for (int i = 0; i < dataQuantity; i++) {
                        cout << setw(12) <<  (i + 1) * dataSize << "\t";
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
                    for (int i = 0; i < dataQuantity; i++) {
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
    Arrays siema(100);
    siema.printArrays();
    cout << "\n\n";
    SearchingAlgorithms siemaneczko(siema.getArray(1), 100, 69);
    siemaneczko.printArray();
    siemaneczko.printAlgorithm();
    siemaneczko.printPosition();
    }

    system("pause");
}
