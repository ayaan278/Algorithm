// Merge Sort concrete implementation
#include "../../Common/dataSet1.h"
using dataSet1::v1;

/*
@author 
@couthelloword
*/
// adjusting the sorting environment for merge sort
void dataSet1::mergeSortSetup(int fileSize, bool ascending)
{
    // locating the data source
    string dataSource = "../../DatasetsSamples/DataSet1/Dataset-" + to_string(fileSize) + ".csv";

    // creating the output file
    ofstream outputFile; // creating file object
    // writing the duration of the sorting process in its appropriate file
    string timeName = "../../Outputs/Question2/MergeSortTime.csv";
    ofstream timeFile(timeName, ios::app);

    // reading the data from source into a vector
    vector<long long int> grandSet = CSVData(dataSource); // the data set
    vector<long long int> temp = CSVData(dataSource); // temporary data structure for sorting



    // noting the timeframe of the sorting process
    auto start = chrono::high_resolution_clock::now();
    // sorting function
    dataSet1::mergeSort(grandSet, temp, 0, fileSize - 1, ascending);
    // end of sorting process
    auto end = chrono::high_resolution_clock::now();
    // duration
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout<< "Time taken by function: " << duration.count() << " microseconds" << endl;

    // writing the data outcomes into 'csv' format
    string outputName;
    if(ascending){
        outputName = "../../Outputs/Question2/MergeSort" + to_string(fileSize) + "Ascending.csv";
    }
    else{
        outputName = "../../Outputs/Question2/MergeSort" + to_string(fileSize) + "Descending.csv";
    }
    outputFile.open(outputName, ios::out);
    // if file is not open, throw an error
    if(!outputFile.is_open())
    {
        cout << "Failed to open file!!!" << endl;
    }
    // writing the data set into the file
    for(int i=0; i<fileSize; i++){
        outputFile << grandSet[i] << "," << endl;
    }
    outputFile.close();
    
    timeFile << to_string(fileSize) << ",\t" << duration.count() << " ms" << endl;
    timeFile.close();
}

void dataSet1::merge(vector<long long>& grandSet, vector<long long>& temp, int p, int pivot, int r, bool ascending)
{
    // if the sorting is in ascending order
    if(ascending){
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
    // if the sorting is in descending order
    else{
        int i, j;
        for (i = pivot + 1; i > p; i--) {
            temp[i - 1] = grandSet[i - 1];
        }

        for (j = pivot; j < r; j++) {
            temp[(r + pivot) - j] = grandSet[j + 1];
        }

        i = p;
        j = r;

        for (int k = p; k <= r; k++) {
            if (temp[i] > temp[j]) {
                grandSet[k] = temp[j++];
            } else {
                grandSet[k] = temp[i--];
            }
        }
    }
}

void dataSet1::mergeSort(vector<long long int>& grandSet, vector<long long int>& temp, int p, int r, bool ascending)
{
    int pivot; // the point where we divide the original data set

    // while there are more than an element in a subset
    if(p < r){
        pivot = (p + r) / 2; // the break point

        // recursive call for the subsets
        mergeSort(grandSet, temp, p, pivot, ascending);
        mergeSort(grandSet, temp, pivot+1, r, ascending);

        // merging the subsets
        dataSet1::merge(grandSet, temp, p, pivot, r, ascending);
    }
}
