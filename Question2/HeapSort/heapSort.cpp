// concrete implementation of heap sort
#include "../../Common/dataSet1.h"
#include "../../Question1/Dataset1/CSVProcessing.cpp"
template <typename T>

/*
@author 
@Musaab2120
*/
class dataSet1::PriorityQueue
{
    // vector to be the container of the priority queue
    vector<T> A;
    // heapifying operation for enqueue
    void heapify_enqueue (int index)
    { // used in heapify enqueue.
        if (index == 0) // if already at root.
            return;
        // get parent index
        int parent_index = (index - 1)/2;
        // swap element with its parent if parent is smaller
        if(A[index] > A[parent_index])
        {
            swap(A[index], A[parent_index]);
            heapify_enqueue(parent_index);
        }
    }
    // heaping operation for enqueue
    void heapify_dequeue (int index)
    { // used in heapify dequeue.
        int max; // max index
        // left child index
        int left = (2*index) + 1;
        // right child index
        int right = (2*index) + 2;
        // compare and find the greatest child
        if(left < A.size() && A[left] > A[index])
        {
            // case where the left child is greater than the parent
            max = left;
        }
        else
        {
            // case where the parent is greater than the left child
            max = index;
        }
        if(right < A.size() && A[right] > A[max])
        {
            // case where the right child is greater than the parent
            max = right;
        }
        // swap parent with the greatest child. if parent is not the greatest
        if (max != index)
        {
            swap (A[index], A[max]);
            heapify_dequeue (max); // recursion
        }
    }
public:
    // insert element into the priority queue
    void enqueue (T element)
    {
        A.push_back (element);
        heapify_enqueue (A.size()-1); // start at last element.
    }
    // remove element from the priority queue
    T dequeue()
    {
        T removed_element = A[0];
        A[0] = A[A.size()-1]; // copy last element to root.
        A.pop_back(); // remove last element.
        heapify_dequeue (0); // start at root.
        return removed_element;
    }
    // return the size of the priority queue
    int size()
    {
        return A.size();
    }
    // print the elements of the priority queue
    void print()
    {
        for (int i = 0; i < A.size(); i++)
            cout << A[i] << " ";
        cout << endl;
    }
};


// adjusting the sorting environment
void dataSet1::heapSortSetup(int fileSize) {
    // locating the data source
    string dataSource = "../../DatasetsSamples/DataSet1/Dataset-" + to_string(fileSize) + ".csv";

    // Read data from the CSV file
    vector<long long int> inputVector = CSVData(dataSource);


    // noting the time frame of the sorting process
    auto start = chrono::high_resolution_clock::now();

    // Priority Queue operations
    dataSet1::PriorityQueue<long long int> pq;
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
