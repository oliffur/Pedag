#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class MaxHeap{
public:
    
    bool checkIndex(int i);
    int getParentIndex(int i);
    int getLeftIndex(int i);
    int getRightIndex(int i);
    
    void maxHeapify(int i);
    
    int size();
    
    int maximum();
    int extractMax();
    void increaseKey(int i, int newKey);
    void insert(int key);
    
private:
    vector<int> heap;
};

int MaxHeap::size(){
    return heap.size();
}

int MaxHeap::getParentIndex(int i){
    if (i/2 >= heap.size()) return 0;
    return i/2;
}

int MaxHeap::getLeftIndex(int i){
    if (2*i >= heap.size()) return 0;
    return 2*i;
}

int MaxHeap::getRightIndex(int i){
    if (2*i+1 >= heap.size()) return 0;
    return 2*i+1;
}

bool MaxHeap::checkIndex(int i){
    if (i==0 || i>=heap.size()) return false;
    return true;
}

void MaxHeap::maxHeapify(int i){
    if (!checkIndex(i)) return;
    int left = getLeftIndex(i);
    int right = getRightIndex(i);
    // find maximum among i, left, right
    int maxIndex;
    if (left != 0 && heap[left] > heap[i]) maxIndex = left;
    else maxIndex = i;
    
    if (right != 0 && heap[right] > heap[maxIndex]) maxIndex = right;
    
    // switch the min index with the root node
    if (maxIndex != i){
        int temp = heap[i];
        heap[i] = heap[maxIndex];
        heap[maxIndex] = temp;
        maxHeapify(maxIndex);
    }
}

int MaxHeap::maximum(){
    if (heap.size()==1) return INT_MIN;
    else return heap[1];
}

int MaxHeap::extractMax(){
    if (heap.size()==1) return INT_MIN;
    int maximum = heap[1];
    heap[1] = heap[heap.size()-1];
    heap.pop_back();
    maxHeapify(1);
    return maximum;
}

void MaxHeap::increaseKey(int i, int newKey){
    if (newKey < heap[i]) return;
    heap[i] = newKey;
    while (i>1 && heap[getParentIndex(i)] > heap[i]){
        int temp = heap[i];
        heap[i] = heap[getParentIndex(i)];
        heap[getParentIndex(i)] = temp;
        i = getParentIndex(i);
    }
}

void MaxHeap::insert(int key){
    heap.push_back(INT_MIN);
    increaseKey(heap.size()-1, key);
}
