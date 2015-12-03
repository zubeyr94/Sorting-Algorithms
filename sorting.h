//
// Zübeyr Furkan Eryilmaz
// 21202676
// CS 202 – 01
//

#ifndef CSS202ASSIGNMENT1_SORTING_H
#define CSS202ASSIGNMENT1_SORTING_H

class sorting
{

    public:

        sorting();
        void selectionSort(int *arr, int size, long long &compCount, long long &moveCount);
        void mergeSort( int *arr, int size, long long &compCount, long long &moveCount);
        void quickSort( int *arr, int size, long long &compCount, long long &moveCount);



    private:

        void mergeSort(int *arr, int first, int last, long long &compCount, long long &moveCount);
        void quickSort(int *arr, int first, int last, long long &compCount, long long &moveCount);
        void swap(int &x, int &y, long long &moveCount);
        int findLargestIndex(int * arr, int size, long long &compCount, long long &moveCount);
        void partition(int *arr, int first, int last, int &pivotIndex, long long &compCount, long long &moveCount);
        void merge(int *arr, int first, int mid, int last, long long &compCount, long long &moveCount);

};
#endif //CSS202ASSIGNMENT1_SORTING_H

