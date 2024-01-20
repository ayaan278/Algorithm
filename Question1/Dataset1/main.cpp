// this interface mainly is to create data set based on given size
#include "../../Common/dataSet1.h"
#include "./CSVProcessing.cpp"
using namespace dataSet1;
using dataSet1::v1;

/*
@author 
@Musaab2120
*/
int main()
{
    int size;
    cout << "Enter the size of file" << endl;
    cin >> size;
    dataSet1::craftData(v1, size);
    cout << "file have being successfully created" << endl;
    return 0;
}
