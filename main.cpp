#include "CommonFiles.h"
#include "Console.h"
#include "Sorting.h"





void calculateTime(vector<int> nums,Sorting& sorting, void (Sorting::*sort)(std::vector<int> nums), const char* name)
{

    // Start timer
    auto start = std::chrono::high_resolution_clock::now();

    // Call the sort function using the function pointer
    (sorting.*sort)(nums);

    // Stop timer
    auto stop = std::chrono::high_resolution_clock::now();

    // Calculate elapsed time
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << name << ": elapsed time = " << elapsed.count() << " microseconds" << std::endl;
}


int main() {
    ios_base::sync_with_stdio(false);

    int x;
    vector<int> A;
    Console* console = Console::getInstance();

    cout<<"Enter size of array to generate the array"<<endl;
    cin >> x;
    srand(time(NULL));
    for(int i=0;i<x;i++) A.push_back(1 + rand() % 10000);
//    for(int i=0;i<x;i++) A.push_back(i);
    console->printValue(A,"Creation");

    cout<<"Created Array after randomization"<<endl;
    Sorting *sort = new Sorting();
    calculateTime(A,*sort, &Sorting::bubbleSort, "Bubble Sort");
    calculateTime(A,*sort, &Sorting::selectionSort, "Selection Sort");
    calculateTime(A,*sort, &Sorting::insertionSort, "Insertion Sort");
    calculateTime(A,*sort, &Sorting::quickSort, "Quick Sort");
    calculateTime(A,*sort, &Sorting::mergeSort, "Merge Sort");
    calculateTime(A,*sort, &Sorting::inBuildSort, "InBuild Sort");
    calculateTime(A,*sort, &Sorting::inBuildQSort, "InBuild Q Sort");
    delete sort;
    return 0;
}


//stack -> vector -> linked list
//vector -> lock & unlock -> time -2ms
//
//arraydeque (arraylist) - 1ms less