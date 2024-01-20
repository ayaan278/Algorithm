#include <bits/stdc++.h>
using namespace std;
template <typename T>
void printArray (T A[], int n) {
for (int i = 0; i < n; i++)
cout << A[i] << " ";
cout << endl;
}
template <typename T>
class PriorityQueue {
vector<T> A;
void heapify_enqueue (int index) { // used in heapify enqueue.
if (index == 0) // if already at root.
return;
int parent_index = (index - 1)/2;
// parent index
if(A[index] < A[parent_index]){
    swap(A[index],A[parent_index]);
    heapify_enqueue(parent_index);
}
// swap if parent is larger
// recursion of the function
}
void heapify_dequeue (int index) { // used in heapify dequeue.
int min; // max index
// left child index
int left = (2*index) + 1;
// right child index
int right = (2*index) + 2;
// compare and find the greatest child
if(left < A.size() && A[left] < A[index]){
    min = left;
}
else{
    min = index;
}
if(right < A.size() && A[right] < A[min]){
    min = right;
}


if (min != index) {
swap (A[index], A[min]);
heapify_dequeue (min); // recursion
}
}
public:
void enqueue (T element) {
    A.push_back (element);
    heapify_enqueue (A.size()-1); // start at last element.
}
T dequeue() {
    T removed_element = A[0];
    A[0] = A[A.size()-1]; // copy last element to root.
    A.pop_back(); // remove last element.
    heapify_dequeue (0); // start at root.
    return removed_element;
}
int size() {
return A.size();
}
void print() {
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





