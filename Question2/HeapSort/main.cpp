// this interface sorts the data sets using heap sort algorithm
#include "../../Common/dataSet1.h"
#include "heapSort.cpp"

/*
@author 
@Musaab2120
*/
int main () 
{
    int size;
    cout << "Enter the size of the file " << endl;
    cin >> size;
    dataSet1::heapSortSetup(size);
    cout << "file have been sorted successfully" << endl;
    return 0;
}