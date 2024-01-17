#include "../../Common/dataSet1.h"
using dataSet1::v1;


// generates the data set, prints it in a 'csv' file format
int dataSet1::craftData(string fileName, vector<int> values, long long int size)
{
    ofstream outputFile; // creating file object
    fileName = fileName + to_string(size) + ".csv"; // label it based on the size of the data set
    outputFile.open(fileName, ios::app);
    // if file is not open, throw an error
    if (!outputFile.is_open())
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }
    // creating the data set
    for (auto i = 0; i < size; i++)
    {
        values = {1,1,9,1,3,0,2,7,9,4};
        random_device rd,rnd;
        mt19937 give(rd());
        uniform_int_distribution<int>gen(1,10);
        shuffle(values.begin(),values.end(),give);
        values.resize(gen(rnd));
        // writing the generated  element into the file
        for (auto& i : values)
        {
            outputFile << i;
        }
        outputFile << "," << endl;
    }
    outputFile.close();
    return 0;
}




// reading from 'csv' file
vector<long long int> dataSet1::CSVData(const string& file_path) {
    vector<long long int> data; // the function output
    ifstream file(file_path); // setting the file object to read from the argument path


    // if file is not open, throw an error
    if (!file.is_open()) {
        cerr << "Error opening file: " << file_path << endl;
        return data;
    }
    // reading the data linearly to the vector
    string line;
    while(getline(file, line)){
        data.push_back(stoll(line));
    }
    file.close();
    return data;
}


