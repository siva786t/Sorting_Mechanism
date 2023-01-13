//
// Created by Sivasubramani on 18/12/22.
//

#ifndef SORTING_SORTING_H
#define SORTING_SORTING_H
#include "CommonFiles.h"
#include "Console.h"

class Sorting {
private:

    Console* console;

public:
    Sorting();
    void bubbleSort(vector<int> nums);
    void selectionSort(vector<int> nums);
    void insertionSort(vector<int> nums);
    void quickSort(vector<int> nums);
    void mergeSort(vector<int> nums);
    void inBuildSort(vector<int> nums);

    void inBuildQSort(vector<int> nums);
};


#endif //SORTING_SORTING_H
