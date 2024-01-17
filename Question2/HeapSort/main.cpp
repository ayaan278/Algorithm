#include <bits/stdc++.h>
using namespace std;

template <typename T>
void printArray (T A[], int n) 
{
    for (int i = 0; i < n; i++)
    cout << A[i] << " ";
    cout << endl;
}

template <typename T>
class PriorityQueue 
{
    vector<T> A;
    void heapify_enqueue (int index) 
    { // used in heapify enqueue.
        if (index == 0) // if already at root.
            return;
        int parent_index = (index - 1)/2;
        // parent index
        if(A[index] > A[parent_index])
        {
            swap(A[index], A[parent_index]);
            heapify_enqueue(parent_index);
        }
    // swap if parent is smaller
    // recursion of the function
    }
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
            max = left;
        }
        else
        {
            max = index;
        }
        if(right < A.size() && A[right] > A[max])
        {
            max = right;
        }

        if (max != index) 
        {
            swap (A[index], A[max]);
            heapify_dequeue (max); // recursion
        }
    }
    public:
    void enqueue (T element) 
    {
        A.push_back (element);
        heapify_enqueue (A.size()-1); // start at last element.
    }
    T dequeue() 
    {
        T removed_element = A[0];
        A[0] = A[A.size()-1]; // copy last element to root.
        A.pop_back(); // remove last element.
        heapify_dequeue (0); // start at root.
        return removed_element;
    }
    int size() 
    {
        return A.size();
    }
    void print() 
    {
        for (int i = 0; i < A.size(); i++)
            cout << A[i] << " ";
        cout << endl;
    }
};


int main () 
{
// Open the CSV file
    ifstream inputFile("../../Dataset/DataSet1/Dataset-10000.csv",ios::in);

   // Check if the file is open
    if (!inputFile.is_open()) 
    {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    // Read numbers from the CSV file
    vector<long long int> inputVector;
    long long int num;
    string line;
    
    if (inputFile.is_open()) 
    {
        string line;
        while (getline(inputFile, line)) 
        {
            stringstream ss(line);

            if (ss >> num) 
            {
                inputVector.push_back(num);
            } 
            else 
            {
                cout << "Failed to parse line: " << line << endl;
            }
        }
    } 
    else 
    {
        cout << "Failed to open file" << endl;
        return 1;
    }

    // Close the file
    inputFile.close();


    // Priority Queue operations
    //cout << "\nEnqueue\t: PriorityQueue\n";
    PriorityQueue<long long int> pq;
    for (int i=0; i<inputVector.size(); i++) 
    {
        pq.enqueue(i);
        // pq.print();
    }


    fstream outputfile;
    outputfile.open("trialdataset.csv", ios::out);

    if(!outputfile.is_open())
    {
        cout << "error opening the file" << endl;
    }

    while (pq.size() > 0)
    {
       // cout << pq.dequeue() << "\t: ";
    //    pq.print();
        outputfile << pq.dequeue() << "," << endl;;
    }
    
    outputfile.close();
   
    return 0;
}