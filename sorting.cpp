//
// Zübeyr Furkan Eryilmaz
// 21202676
// CS 202 – 01
//

#include "sorting.h"

sorting::sorting(){}

void sorting::selectionSort(int *arr, int size, long long &compCount, long long &moveCount) {

    int largest;

    for( int last = size -1  ; last > 0 ; last--)
    {
        largest = findLargestIndex(arr,last+1,compCount,moveCount);
        swap(arr[last],arr[largest],moveCount);
    }
}

//  Calls mergeSort function according to given size
void sorting::mergeSort( int *arr, int size, long long &compCount, long long &moveCount) {

    mergeSort(arr, 0, size-1, compCount, moveCount);

}

//  Calls quickSort function according to given size
void sorting::quickSort( int *arr, int size, long long &compCount, long long &moveCount){

    quickSort(arr, 0, size-1, compCount, moveCount);

}

void sorting::mergeSort(int *arr, int first, int last, long long &compCount, long long &moveCount){

    if (first < last)
    {
        int mid = (first + last) / 2;

        mergeSort(arr, first, mid, compCount, moveCount);
        mergeSort(arr, mid+1, last, compCount, moveCount);

        merge(arr, first, mid, last, compCount, moveCount);
    }

    compCount++;

}

void sorting::quickSort(int *arr, int first, int last, long long &compCount, long long &moveCount){

    int pivotIndex;

    if(first < last)
    {
        partition(arr, first, last, pivotIndex, compCount, moveCount);
        quickSort(arr,first, pivotIndex-1, compCount, moveCount);
        quickSort(arr, pivotIndex+1, last, compCount, moveCount);
    }

    compCount++;

}

//  Swaps given elements
void sorting::swap(int &x, int &y, long long &moveCount){
    int temp = x;
    x = y;
    y = temp;
    moveCount+=3;
}

//  Returns the index of the largest element in the specified size of the array
int sorting::findLargestIndex(int * arr, int size, long long &compCount, long long &moveCount){

    int max = 0;
    for(int i =1; i< size;i++){
        if(arr[i] > arr[max])
        {
            max = i;
            moveCount++;
        }
        compCount++;
    }
    return max;
}

//  Partitions the array in the given interval and returns the pivot's index
void sorting::partition(int *arr, int first, int last, int &pivotIndex, long long &compCount, long long &moveCount){

    pivotIndex = last;
    moveCount++;

    for ( int index = last; index > first; index--)
    {
        if ( arr[index] > arr[first])
        {
            swap(arr[index], arr[pivotIndex],moveCount);
            pivotIndex--;
            moveCount++;
        }

        compCount++;
    }

    swap(arr[pivotIndex], arr[first], moveCount);
}

//  Merges the splitted arrays
void sorting::merge(int *arr, int first, int mid, int last, long long &compCount, long long &moveCount){

    int temp[last-first+1];

    int first1 = first;
    int last1 = mid;
    int first2 = mid+1;
    int last2 = last;

    moveCount+=4;

    int index = 0;

//    Compares and puts first the smaller one until one of the two array is finished
    for (;(first1 <= last1)&&(first2 <= last2); index++)
    {

        if(arr[first1] < arr[first2]) {

            temp[index] = arr[first1];
            first1++;
        }
        else
        {
            temp[index] = arr[first2];
            first2++;
        }

        moveCount+=2;
        compCount++;

    }

//    If not the first array finished puts remaining elements in the first array
    for(;first1<=last1; index++, first1++)
    {
        temp[index] = arr[first1];
        moveCount+=2;
    }

//    If not the second array finished puts remaining elements in the second array
    for(;first2<=last2; first2++, index++)
    {
        temp[index] = arr[first2];
        moveCount+=2;
    }

//    Puts sorted values in the temp array back in to the original array
    for(int i = 0; i <= last-first; i++)
    {
        arr[first+i] = temp[i];
        moveCount++;
    }

}

