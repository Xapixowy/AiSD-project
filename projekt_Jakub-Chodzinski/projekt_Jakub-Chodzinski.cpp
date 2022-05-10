#include <iostream>
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
    cout << "AiSD - Projekt\n\n";
    fstream data;
    string fileName = "", folderName="data";
    int dataQuantity = 0, dataSize = 0, dataMin, dataMax, searchingValue;
    char saveToFile = 'a', showData = 'a';
    if (debug) {
        dataQuantity = 100;
        dataSize = 100;
        dataMin = 0;
        dataMax = 100;
        searchingValue = 69;
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
        while (dataMin >= dataMax);
        cout << "Podaj wyszukiwana wartosc dla algorytmow wyszukiwania (>=min i <=max): ";
        do
            cin >> searchingValue;
        while (searchingValue < dataMin || searchingValue > dataMax);
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
    cout << "========================================\n\n";

    // Tworzenie obiektow
    cout << "[ ] Tworzenie obiektow...";
    Arrays** tablice = new Arrays * [dataQuantity];
    SortingAlgorithms** sortowanieTablicLosowych = new SortingAlgorithms * [dataQuantity];
    SortingAlgorithms** sortowanieTablicRosnacych = new SortingAlgorithms * [dataQuantity];
    SortingAlgorithms** sortowanieTablicMalejacych = new SortingAlgorithms * [dataQuantity];
    SearchingAlgorithms** przeszukiwanieTablicLosowych = new SearchingAlgorithms * [dataQuantity];
    SearchingAlgorithms** przeszukiwanieTablicRosnacych = new SearchingAlgorithms * [dataQuantity];
    SearchingAlgorithms** przeszukiwanieTablicMalejacych = new SearchingAlgorithms * [dataQuantity];

    for (int i = 0; i < dataQuantity; i++) {
        tablice[i] = new Arrays((i+1)*dataSize, dataMax, dataMin);
        sortowanieTablicLosowych[i] = new SortingAlgorithms(tablice[i]->getArray(0), (i + 1) * dataSize);
        sortowanieTablicRosnacych[i] = new SortingAlgorithms(tablice[i]->getArray(1), (i + 1) * dataSize);
        sortowanieTablicMalejacych[i] = new SortingAlgorithms(tablice[i]->getArray(2), (i + 1) * dataSize);
        przeszukiwanieTablicLosowych[i] = new SearchingAlgorithms(tablice[i]->getArray(0), (i + 1) * dataSize, searchingValue);
        przeszukiwanieTablicRosnacych[i] = new SearchingAlgorithms(tablice[i]->getArray(1), (i + 1) * dataSize, searchingValue);
        przeszukiwanieTablicMalejacych[i] = new SearchingAlgorithms(tablice[i]->getArray(2), (i + 1) * dataSize, searchingValue);
    }
    cout << "\r[X] Obiekty stworzone!   \n";

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
            data << sortowanieTablicLosowych[i]->getDominantOperations(0) << ";";
            data << sortowanieTablicRosnacych[i]->getDominantOperations(0) << ";";
            data << sortowanieTablicMalejacych[i]->getDominantOperations(0) << "\n";
        }
        for (int i = 0; i < dataQuantity; i++) {
            data << "sortowanie przez wstawianie;";
            data << (i + 1) * dataSize << ";";
            data << sortowanieTablicLosowych[i]->getDominantOperations(1) << ";";
            data << sortowanieTablicRosnacych[i]->getDominantOperations(1) << ";";
            data << sortowanieTablicMalejacych[i]->getDominantOperations(1) << "\n";
        }
        for (int i = 0; i < dataQuantity; i++) {
            data << "sortowanie przez scalanie;";
            data << (i + 1) * dataSize << ";";
            data << sortowanieTablicLosowych[i]->getDominantOperations(2) << ";";
            data << sortowanieTablicRosnacych[i]->getDominantOperations(2) << ";";
            data << sortowanieTablicMalejacych[i]->getDominantOperations(2) << "\n";
        }
        for (int i = 0; i < dataQuantity; i++) {
            data << "wyszukiwanie liniowe;";
            data << (i + 1) * dataSize << ";";
            data << przeszukiwanieTablicLosowych[i]->getDominantOperations(0) << ";";
            data << przeszukiwanieTablicRosnacych[i]->getDominantOperations(0) << ";";
            data << przeszukiwanieTablicMalejacych[i]->getDominantOperations(0) << "\n";
        }
        for (int i = 0; i < dataQuantity; i++) {
            data << "wyszukiwanie binarne;";
            data << (i + 1) * dataSize << ";";
            data << przeszukiwanieTablicLosowych[i]->getDominantOperations(1) << ";";
            data << przeszukiwanieTablicRosnacych[i]->getDominantOperations(1) << ";";
            data << przeszukiwanieTablicMalejacych[i]->getDominantOperations(1) << "\n";
        }
        data.close();
        cout << "\r[X] Dane zapisane do pliku!       \n";
    }

    cout << "\n========================================\n\n";

    // Wyswietlanie danych
    if (showData == 'y') {
        cout << (char)(175) << " Tablice losowe:\n" << "--------------------\n";
        for (int i = 0; i < dataQuantity; i++) {
            cout << "Tablica losowa [" << (i + 1) * dataSize << "]:\n";
            sortowanieTablicLosowych[i]->printDominantOperations();
            przeszukiwanieTablicLosowych[i]->printDominantOperations();
        }
        cout << "\n" << (char)(175) << " Tablice rosnace:\n" << "--------------------\n";;
        for (int i = 0; i < dataQuantity; i++) {
            cout << "Tablica rosnaca [" << (i + 1) * dataSize << "]:\n";
            sortowanieTablicRosnacych[i]->printDominantOperations();
            przeszukiwanieTablicRosnacych[i]->printDominantOperations();
        }
        cout << "\n" << (char)(175) << " Tablice malejace:\n" << "--------------------\n";;
        for (int i = 0; i < dataQuantity; i++) {
            cout << "Tablica malejaca [" << (i + 1) * dataSize << "]:\n";
            sortowanieTablicMalejacych[i]->printDominantOperations();
            przeszukiwanieTablicMalejacych[i]->printDominantOperations();
        }
    }

    system("pause");
}
