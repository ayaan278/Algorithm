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
    bool sortchoice;
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
    
    cout<<"|------------------------------------------------------------------|"<<endl;
    cout<<"|            Enter Choice                                          |"<<endl;
    cout<<"|------------------------------------------------------------------|"<<endl;
    cout<<"| Enter 1 for max Sorting                                          |"<<endl;
    cout<<"| Enter 0 for min Sorting                                          |"<<endl;
    cout<<"| Enter x to exit                                                  |"<<endl;
    cout<<"|------------------------------------------------------------------|"<<endl;
    cin >> sortchoice; 
    switch(size){
        case 1:
            size = 100;
            dataSet1::HeapSortSetup(size,sortchoice);
            cout << "file have being successfully sorted" << endl;
            break;
        case 2:
            size = 1000;
            dataSet1::HeapSortSetup(size,sortchoice);
            cout << "file have being successfully sorted" << endl;
            break;
        case 3:
            size = 10000;
            dataSet1::HeapSortSetup(size,sortchoice);
            cout << "file have being successfully sorted" << endl;
            break;
        case 4:
            size = 100000;
            dataSet1::HeapSortSetup(size,sortchoice);
            cout << "file have being successfully sorted" << endl;
            break;
        case 5:
            size = 500000;
            dataSet1::HeapSortSetup(size,sortchoice);
            cout << "file have being successfully sorted" << endl;
            break;
    }

    return 0;
    //dataSet1::minHeapSortSetup(size);
    //cout << "file have been sorted successfully" << endl;
    //return 0;
}