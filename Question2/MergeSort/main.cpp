// this interface sorts the data sets using heap sort algorithm
#include "../../Common/dataSet1.h"
#include "../../Question1\Dataset1\CSVProcessing.cpp"

#include "./mergeSort.cpp"

int main(){
    int size;
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

    int choice;
    cin>>choice;

    cout<<"|------------------------------------------------------------------|"<<endl;
    cout<<"|            Enter Choice                                          |"<<endl;
    cout<<"|------------------------------------------------------------------|"<<endl;
    cout<<"| Enter 1 for Max heap                                             |"<<endl;
    cout<<"| Enter 2 for Min heap                                             |"<<endl;
    cout<<"| Enter 0 to exit                                                  |"<<endl;
    cout<<"|------------------------------------------------------------------|"<<endl;

    int heapChoice;
    cin>>heapChoice;

    cout << "Enter the size of file" << endl;
    cin >> size;
    dataSet1::mergeSortSetup(size);
    cout << "file have being successfully sorted" << endl;
    return 0;
}
