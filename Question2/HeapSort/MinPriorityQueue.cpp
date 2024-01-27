#include "../../Common/dataSet1.h"
template <typename T>


class dataSet1::MinPriorityQueue
{
    // vector to be the container of the priority queue
    vector<T> A;
    // heapifying operation for enqueue
    void heapify_enqueue (int index)
    { 
        // heapify min 
        if (index == 0) // if already at root.
            return;

        // get parent index
        int parent_index = (index - 1)/2;

        // swap element with its parent if parent is greater
        if(A[index] < A[parent_index])
        {
            swap(A[index], A[parent_index]);
            heapify_enqueue(parent_index);
        }
    }
    // heaping operation for enqueue
    void heapify_dequeue (int index)
    { // used in heapify dequeue.
        int min; // min index
        // left child index
        int left = (2*index) + 1;
        // right child index
        int right = (2*index) + 2;
        // compare and find the smallest child
        if(left < A.size() && A[left] < A[index])
        {
            // case where the left child is smaller than the parent
            min = left;
        }
        else
        {
            // case where the parent is smaller than the left child
            min = index;
        }
        if(right < A.size() && A[right] < A[min])
        {
            // case where the right child is smaller than the parent
            min = right;
        }
        // swap parent with the smallest child. if parent is not the smallest
        if (min != index)
        {
            swap (A[index], A[min]);
            heapify_dequeue (min); // recursion
        }
    }
    public:
    void enqueue (T element) 
    {
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
    int size() 
    {
        return A.size();
    }
};


