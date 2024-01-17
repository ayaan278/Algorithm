#pragma once
#ifndef DATASET1_H
#define DATASET1_H
#include<bits/stdc++.h>
using namespace std;

namespace dataSet1
{
    // container of valid number
    inline vector<int> v1 = {1,1,9,1,3,0,2,7,9,4};

    // data generator
    int craftData(string fileName, vector<int> values, long long int size);

    // 'csv' file reader
    vector<long long int> CSVData(const string& dataSource);

    // sorting starter
    void mergeSortSetup(int fileSize);

    // merge sort
    void mergeSort(vector<long long int>& grandSet, vector<long long int>& temp, int p, int r);

    // merger
    void merge(vector<long long int>& grandSet, vector<long long int>& temp, int p, int pivot, int r);

    // heap sort
    void heapSort();

    // interface
    void interface();
};
#endif // DATASET1_H

