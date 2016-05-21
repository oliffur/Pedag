#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MinHeap{
public:
    
    bool checkIndex(int i);
    int getParentIndex(int i);
    int getLeftIndex(int i);
    int getRightIndex(int i);
    
    void maxHeapify(int i);
    
    int size();
    
    int minimum();
    int extractMin();
    void decreaseKey(int i, int newKey);
    void insert(int key);
    
private:
    vector<int> heap;
};

int MinHeap::size(){
    return heap.size();
}

int MinHeap::getParentIndex(int i){
    if (i/2 >= heap.size()) return 0;
    return i/2;
}

int MinHeap::getLeftIndex(int i){
    if (2*i >= heap.size()) return 0;
    return 2*i;
}

int MinHeap::getRightIndex(int i){
    if (2*i+1 >= heap.size()) return 0;
    return 2*i+1;
}

bool MinHeap::checkIndex(int i){
    if (i==0 || i>=heap.size()) return false;
    return true;
}

void MinHeap::minHeapify(int i){
    if (!checkIndex(i)) return;
    int left = getLeftIndex(i);
    int right = getRightIndex(i);
    // find minimum among i, left, right
    int minIndex;
    if (left != 0 && heap[left] < heap[i]) minIndex = left;
    else minIndex = i;
    
    if (right != 0 && heap[right] < heap[minIndex]) minIndex = right;
    
    // switch the min index with the root node
    if (minIndex != i){
        int temp = heap[i];
        heap[i] = heap[minIndex];
        heap[minIndex] = temp;
        minHeapify(minIndex);
    }
}

int MinHeap::minimum(){
    if (heap.size()==1) return INT_MAX;
    else return heap[1];
}

int MinHeap::extractMin(){
    if (heap.size()==1) return INT_MAX;
    int min = heap[1];
    heap[1] = heap[heap.size()-1];
    heap.pop_back();
    maxHeapify(1);
    return min;
}

void MinHeap::decreaseKey(int i, int newKey){
    if (newKey > heap[i]) return;
    heap[i] = newKey;
    while (i>1 && heap[getParentIndex(i)] < heap[i]){
        int temp = heap[i];
        heap[i] = heap[getParentIndex(i)];
        heap[getParentIndex(i)] = temp;
        i = getParentIndex(i);
    }
}

void MinHeap::insert(int key){
    heap.push_back(INT_MAX);
    decreaseKey(heap.size()-1, key);
}
