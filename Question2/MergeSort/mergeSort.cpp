// Merge Sort concrete implementation
#include "../../Common/dataSet1.h"
using dataSet1::v1;

// adjusting the sorting environment for merge sort
void dataSet1::mergeSortSetup(int fileSize){
    // locating the data source
    string dataSource = "../../DatasetsSamples/DataSet1/Dataset-" + to_string(fileSize) + ".csv";

    // reading the data from source into a vector
    vector<long long int> grandSet = CSVData(dataSource); // the data set
    vector<long long int> temp = CSVData(dataSource); // temporary data structure for sorting



    // noting the timeframe of the sorting process
    auto start = chrono::high_resolution_clock::now();
    // sorting function
    dataSet1::mergeSort(grandSet, temp, 0, fileSize - 1);
    // end of sorting process
    auto end = chrono::high_resolution_clock::now();
    // duration
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);



    // writing the data outcomes into 'csv' format
    ofstream outputFile; // creating file object

    string name = "../../Outputs/Question2/MergeSort" + to_string(fileSize) + ".csv"; 
    outputFile.open(name, ios::out);
    // if file is not open, throw an error
    if(!outputFile.is_open())
    {
        cout << "Failed to open file!!!" << endl;
    }


    // writing the data set into the file
    // title of the file
    outputFile << "MergedSort version of " + to_string(fileSize) + " file" << endl;
    for(int i=0; i<fileSize; i++){
        outputFile << grandSet[i] << "," << endl;
    }
    // writing the duration of the sorting process
    outputFile << "Time taken to sort: " << duration.count() << " microseconds" << endl;
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
