// this interface sorts the data sets using heap sort algorithm
#include "../../Common/dataSet1.h"
#include "../../Question1\Dataset1\CSVProcessing.cpp"

#include "./mergeSort.cpp"

int main(){
    int size, ascending;
    cout<<"|------------------------------------------------------------------|"<<endl;
    cout<<"|            This is the Merge sort                                |"<<endl;
    cout<<"|------------------------------------------------------------------|"<<endl;
    cout<<"| Enter 1 for Ascending Sorting                                    |"<<endl;
    cout<<"| Enter 0 for Descending Sorting                                   |"<<endl;
    cout<<"|------------------------------------------------------------------|"<<endl;
    cin >> ascending; 

    cout<<"|------------------------------------------------------------------|"<<endl;
    cout<<"|            This is the Merge sort for existing Data files        |"<<endl;
    cout<<"|------------------------------------------------------------------|"<<endl;
    cout<<"| Enter 1 to read Dataset-100.csv                                  |"<<endl;
    cout<<"| Enter 2 to read Dataset-1000.csv                                 |"<<endl;
    cout<<"| Enter 3 to read Dataset-10000.csv                                |"<<endl;
    cout<<"| Enter 4 to read Dataset-100000.csv                               |"<<endl;
    cout<<"| Enter 5 to read Dataset-500000.csv                               |"<<endl;
    cout<<"| Enter any key to exit                                            |"<<endl;
    cout<<"|------------------------------------------------------------------|"<<endl;

    cin>>size;

  
    switch(size)
    {
        case 1:
            size = 100;
            dataSet1::mergeSortSetup(size, ascending);
            cout << "file have being successfully sorted" << endl;
            break;
        case 2:
            size = 1000;
            dataSet1::mergeSortSetup(size, ascending);
            cout << "file have being successfully sorted" << endl;
            break;
        case 3:
            size = 10000;
            dataSet1::mergeSortSetup(size, ascending);
            cout << "file have being successfully sorted" << endl;
            break;
        case 4:
            size = 100000;
            dataSet1::mergeSortSetup(size, ascending);
            cout << "file have being successfully sorted" << endl;
            break;
        case 5:
            size = 500000;
            dataSet1::mergeSortSetup(size, ascending);
            cout << "file have being successfully sorted" << endl;
            break;
        default:
            cout << "Exiting..." << endl;
            break;
    }

    return 0;
}
