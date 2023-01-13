//
// Created by Sivasubramani on 18/12/22.
//

#include "Sorting.h"
void Sorting::bubbleSort(vector<int> nums){
    vector<int> A = nums;
    int size = A.size();
    bool swapped = true;
    while(swapped){
        swapped = false;
        for(int i=1;i<size;i++){
            if(A[i] < A[i-1]){
                swap(A[i],A[i-1]);
                swapped =true;
            }
        }
    }

    console->printValue(A,"Bubble Sort");
}
void Sorting::selectionSort(vector<int> nums){
    vector<int> A = nums;
    for(int i=0;i<A.size()-1;i++){
        for(int j=i+1;j<A.size();j++){
            if(A[i] > A[j]){
                swap(A[i],A[j]);
            }
        }
    }
    console->printValue(A,"Selection Sort");
}
void Sorting::insertionSort(vector<int> nums){
    vector<int> A = nums;

    for(int i=1;i<A.size();i++){
        int j=i-1;
        int key = A[i];
        while(j>=0 && key < A[j]){
            swap(A[j+1],A[j]);
            j--;
        }
    }
    console->printValue(A,"Insertion Sort");
}
int qSort(vector<int> &A, int low,int high){
    int index = A[high];
    int j=low-1;
    for(int i=low;i<=high-1;i++){
        if(index > A[i]){
            j++;
            swap(A[i],A[j]);
        }
    }
    swap(A[j+1],A[high]);
    return (j+1);
}
void quickSorting(vector<int> &A, int low,int high){
    if(low<high){
        int pivotIndex = qSort(A,low,high);
        quickSorting(A,low,pivotIndex-1);
        quickSorting(A,pivotIndex+1,high);
    }
}
void Sorting::quickSort(vector<int> nums){
    vector<int> A = nums;
    quickSorting(A,0,A.size()-1);
    console->printValue(A,"Quick Sort");

}
void merge(vector<int> &A, int low, int mid, int high){
    int i=low;
    int j= mid+1;
    vector<int> temp;
    while(i<=mid && j<=high){
        if(A[i] < A[j]){
            temp.push_back(A[i++]);
        }
        else temp.push_back(A[j++]);
    }
    while(i<=mid){
        temp.push_back(A[i++]);
    }
    while(j<=high){
        temp.push_back(A[j++]);
    }
    for(int i=low;i<=high;i++){
        A[i] = temp[i-low];
    }
}
void mergeSorting(vector<int> &A, int low, int high){
    if(low < high){
        int mid = low + (high -low)/2;
        mergeSorting(A,low,mid);
        mergeSorting(A,mid+1,high);
        merge(A,low,mid,high);
    }


}
void Sorting::mergeSort(vector<int> nums){
    vector<int> A = nums;
    mergeSorting(A,0,A.size()-1);
    console->printValue(A,"Merge Sort");
}

Sorting::Sorting() {
     console = Console ::getInstance();
}
int compare(const void* a, const void *b){
    const int *x = (int*) a;
    const int *y = (int*) b;
    if(*x > *y) return 1;
    else if(*x< *y) return -1;
    return 0;
}
void Sorting::inBuildSort(vector<int> nums) {
    vector<int> A = nums;
    sort(A.begin(),A.end());
    console->printValue(A,"InBuild Sort");
}
void Sorting::inBuildQSort(vector<int> nums) {
    int A[nums.size()];
    for(int i=0;i<nums.size();i++){
        A[i] = nums[i];
    }
    qsort(A,nums.size(),sizeof(int),compare);
//    console->printValue(A,"InBuild Sort");
}
