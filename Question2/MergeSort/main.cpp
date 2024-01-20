// this interface sorts the data sets using heap sort algorithm
#include "../../Common/dataSet1.h"
#include "../../Question1\Dataset1\CSVProcessing.cpp"

#include "./mergeSort.cpp"

int main(){
    int size;
    cout << "Enter the size of file" << endl;
    cin >> size;
    dataSet1::mergeSortSetup(size);
    cout << "file have being successfully sorted" << endl;
    return 0;
}
