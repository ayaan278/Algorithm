// this interface sorts the data sets using heap sort algorithm
#include "../../Common/dataSet1.h"
#include "HeapSort.cpp"
#include "../../Question1/Dataset1/CSVProcessing.cpp"


/*
@author 
@Musaab2120
*/
int main () 
{
    int size;
    cout<<"|------------------------------------------------------------------|"<<endl;
    cout<<"|            This is the Merge sort for existing Data files        |"<<endl;
    cout<<"|------------------------------------------------------------------|"<<endl;
    cout<<"| Enter 1 to read Dataset-100.csv                                  |"<<endl;
    cout<<"| Enter 2 to read Dataset-1000.csv                                 |"<<endl;
    cout<<"| Enter 3 to read Dataset-10000.csv                                |"<<endl;
    cout<<"| Enter 4 to read Dataset-100000.csv                               |"<<endl;
    cout<<"| Enter 5 to read Dataset-500000.csv                               |"<<endl;
    cout<<"| Enter 0 to exit                                                  |"<<endl;
    cout<<"|------------------------------------------------------------------|"<<endl;

    cout << "Enter the size of the file " << endl;
    cin >> size;
    
    dataSet1::minHeapSortSetup(size);
    cout << "file have been sorted successfully" << endl;
    return 0;
}