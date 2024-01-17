// Merge Sort implementation
#include "../../Common/dataSet1.h"
using dataSet1::v1;


void dataSet1::mergeSortSetup(int fileSize){
    // defining the appropriate set to read
    string dataSource;
    switch(fileSize){
        case 100:
            dataSource = ""; // path for the 'csv' file sized as 100
            break;
        case 1000:
            dataSource = ""; // path for the 'csv' file sized as 1000
            break;
        case 10000:
            dataSource = ""; // path for the 'csv' file sized as 10000
            break;
        case 100000:
            dataSource = ""; // path for the 'csv' file sized as 100000
            break;
        case 500000:
            dataSource = ""; // path for the 'csv' file sized as 500000
            break;
    }

    vector<long long int> grandSet = CSVData(dataSource); // the data set
    vector<long long int> temp = CSVData(dataSource); // temporary data structure for sorting

    // sorting function
    dataSet1::mergeSort(grandSet, temp, 0, fileSize - 1);


    // writing the data outcomes into 'csv' format
    ofstream outputFile; // creating file object
    string name = "sorted" + to_string(fileSize) + ".csv"; // label it based on the size of the data set
    outputFile.open(name, ios::app);
    // if file is not open, throw an error
    if(!outputFile.is_open()){
        cout << "Failed to open file!!!" << endl;
    }
    // writing the data set into the file
    outputFile << "Sorted version of " + to_string(fileSize) + " file" << endl;
    for(int i=0; i<fileSize; i++){
        outputFile << grandSet[i] << "," << endl;
    }
}

void dataSet1::merge(vector<long long>& grandSet, vector<long long>& temp, int p, int pivot, int r)
{
    int i, j;
    for(i=pivot+1; i>p; i--){
        temp[i -1] = grandSet[i -1];
    }

    for(j=pivot; j<r; j++){
        temp[(r+pivot) - j] = grandSet[j + 1];
    }

    for(int k=p; k<=r; k++){
        if(temp[j] < temp[i]){
            grandSet[k] = temp[j--];
        }
        else{
            grandSet[k] = temp[i++];
        }
    }
}

void dataSet1::mergeSort(vector<long long int>& grandSet, vector<long long int>& temp, int p, int r)
{
    int pivot; // the point where we divide the original data set

    // while there are more than an element in a subset
    if(p < r){
        pivot = (p + r) / 2; // the break point

        // recursive call for the subsets
        mergeSort(grandSet, temp, p, pivot);
        mergeSort(grandSet, temp, pivot+1, r);

        // merging the subsets
        dataSet1::merge(grandSet, temp, p, pivot, r);
    }
}
