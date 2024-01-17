#include "../../Common/dataSet1.h"
#include "./CSVProcessing.cpp"
using namespace dataSet1;
using dataSet1::v1;


int main()
{
    long long int size;
    cout << "Enter the size of file" << endl;
    cin >> size;

    dataSet1::craftData(v1, size);
    return 0;
}
