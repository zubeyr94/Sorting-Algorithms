//
// Zübeyr Furkan Eryilmaz
// 21202676
// CS 202 – 01
//

#include <iostream>
#include "sorting.h"
#include <time.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char* args[]) {

    sorting sortWith;

    clock_t executionTime;

    const int numberOfElements = 100000;
//  Arrays for different algorithms
    int arr1S[numberOfElements];
    int arr1M[numberOfElements];
    int arr1Q[numberOfElements];

//Creates random array
    for (int i = 0; i < numberOfElements; i++){

        arr1S[i] = rand();
        arr1M[i] = arr1S[i];
        arr1Q[i] = arr1M[i];

    }
//  Creates ascending order array
//    for (int i = 0; i < numberOfElements; i++){
//
//        arr1S[i] = i;
//        arr1M[i] = i;
//        arr1Q[i] = i;
//
//    }

//    Creates descending order array
//    for (int i = numberOfElements-1; i >= 0; i--){
//
//        arr1S[i] = i;
//        arr1M[i] = i;
//        arr1Q[i] = i;
//
//    }

//    Selection Sort
    cout << "Number of elements in the array = " << numberOfElements << endl;
    cout << "Selection Sort" << endl;
    long long compCount = 0;
    long long moveCount = 0;
    executionTime = clock();
    sortWith.selectionSort(arr1S, numberOfElements, compCount, moveCount);
    executionTime = clock() - executionTime;
    cout << "Execution Time(ms) = " << (double)executionTime*1000/CLOCKS_PER_SEC << endl;
    cout << "Number of key comparisons = " << compCount << endl;
    cout << "Number of movements = " << moveCount << endl << endl;

//  Merge Sort
    compCount = 0;
    moveCount = 0;
    executionTime = clock();
    cout << "Merge Sort" << endl;
    sortWith.mergeSort(arr1M, numberOfElements, compCount, moveCount);
    executionTime = clock() - executionTime;
    cout << "Execution Time(ms) = " << (double)executionTime*1000/CLOCKS_PER_SEC << endl;
    cout << "Number of key comparisons = " << compCount << endl;
    cout << "Number of movements = " << moveCount << endl << endl;

//    Quick Sort
    compCount = 0;
    moveCount = 0;
    executionTime = clock();
    cout << "Quick Sort" << endl;
    sortWith.quickSort(arr1Q, numberOfElements, compCount, moveCount);
    executionTime = clock() - executionTime;
    cout << "Execution Time(ms) = " << (double)executionTime*1000/CLOCKS_PER_SEC << endl;
    cout << "Number of key comparisons = " << compCount << endl;
    cout << "Number of movements = " << moveCount << endl;

     return 0;
}
