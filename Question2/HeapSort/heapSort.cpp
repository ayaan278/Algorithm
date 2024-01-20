// concrete implementation of heap sort
#include "../../Common/dataSet1.h"
#include "./MaxPriorityQueue.cpp"
#include "./MinPriorityQueue.cpp"
using dataSet1::MaxPriorityQueue;
using dataSet1::MinPriorityQueue;


namespace dataSet1
{
    
    // adjusting the sorting environment
    void maxHeapSortSetup(int fileSize) 
    {
        // locating the data source
        string dataSource = "../../DatasetsSamples/DataSet1/Dataset-" + to_string(fileSize) + ".csv";

        // Read data from the CSV file
        vector<long long int> inputVector = CSVData(dataSource);

        // noting the time frame of the sorting process
        auto start = chrono::high_resolution_clock::now();

        // Priority Queue operations
        MaxPriorityQueue<long long int> pq;
        for (int i=0; i<inputVector.size(); i++)
        {
            pq.enqueue(i);
        }
        // end of heap sorting
        auto end = chrono::high_resolution_clock::now();
        // duration
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

        // writing the sorted data into a 'csv' file
        fstream outputfile; // file object
        string name = "../../Outputs/Question2/HeapSort" + to_string(fileSize) + ".csv"; // label the file
        outputfile.open(name, ios::out);

        // handling the error of opening the file
        if(!outputfile.is_open())
        {
            cout << "error opening the file" << endl;
        }

        // title of the file
        outputfile << "HeapSort version of " + to_string(fileSize) + " file" << endl;
        while (pq.size() > 0)
        {
            // cout << pq.dequeue() << "\t: ";
            //    pq.print();
            outputfile << pq.dequeue() << "," << endl;;
        }

        // writing the duration of the sorting process
        outputfile << "Time taken to sort: " << duration.count() << " microseconds" << endl;

        outputfile.close();
    }

    // adjusting the sorting environment
    void minHeapSortSetup(int fileSize) 
    {
        // locating the data source
        string dataSource = "../../DatasetsSamples/DataSet1/Dataset-" + to_string(fileSize) + ".csv";

        // Read data from the CSV file
        vector<long long int> inputVector = CSVData(dataSource);


        // noting the time frame of the sorting process
        auto start = chrono::high_resolution_clock::now();

        // Priority Queue operations
        MinPriorityQueue<long long int> pq;
        for (int i=0; i<inputVector.size(); i++)
        {
            pq.enqueue(i);
        }
        // end of heap sorting
        auto end = chrono::high_resolution_clock::now();
        // duration
        auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

        // writing the sorted data into a 'csv' file
        fstream outputfile; // file object
        string name = "../../Outputs/Question2/HeapSort" + to_string(fileSize) + ".csv"; // label the file
        outputfile.open(name, ios::out);

        // handling the error of opening the file
        if(!outputfile.is_open())
        {
            cout << "error opening the file" << endl;
        }

        // title of the file
        outputfile << "HeapSort version of " + to_string(fileSize) + " file" << endl;
        while (pq.size() > 0)
        {
            // cout << pq.dequeue() << "\t: ";
            //    pq.print();
            outputfile << pq.dequeue() << "," << endl;
        }

        // writing the duration of the sorting process
        outputfile << "Time taken to sort: " << duration.count() << " microseconds" << endl;

        outputfile.close();
    }
    
}