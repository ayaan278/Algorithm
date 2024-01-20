// this interface sorts the data sets using heap sort algorithm
#include "../../Common/dataSet1.h"
#include "../../Question1\Dataset1\CSVProcessing.cpp"

#include "./mergeSort.cpp"

int main(){
    int size, orderChoice;
    //TODO
    //Correct the interface
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

    cin>>size;
    system("cls");

    cout<<"|------------------------------------------------------------------|"<<endl;
    cout<<"|            Enter Choice                                          |"<<endl;
    cout<<"|------------------------------------------------------------------|"<<endl;
    cout<<"| Enter 1 for Ascending Sorting                                              |"<<endl;
    cout<<"| Enter 2 for Descending Sorting                                             |"<<endl;
    cout<<"| Enter 0 to exit                                                  |"<<endl;
    cout<<"|------------------------------------------------------------------|"<<endl;
    cin >> orderChoice; // not used yet

    switch(size){
        case 1:
            size = 100;
            dataSet1::mergeSortSetup(size);
            cout << "file have being successfully sorted" << endl;
            break;
        case 2:
            size = 1000;
            dataSet1::mergeSortSetup(size);
            cout << "file have being successfully sorted" << endl;
            break;
        case 3:
            size = 10000;
            dataSet1::mergeSortSetup(size);
            cout << "file have being successfully sorted" << endl;
            break;
        case 4:
            size = 100000;
            dataSet1::mergeSortSetup(size);
            cout << "file have being successfully sorted" << endl;
            break;
        case 5:
            size = 500000;
            dataSet1::mergeSortSetup(size);
            cout << "file have being successfully sorted" << endl;
            break;
    }

    return 0;
}
