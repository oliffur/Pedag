/* merges k sorted arrays in time O(n log n)
 * 
 */

#include <iostream>
#include "MinHeap.h"
#include <vector>

using namespace std;

void minHeapifyModified(MinHeap& heap, int i, vector<vector<int>>& arrays){
    if (!heap.checkIndex(i)) return;
    int left = heap.getLeftIndex(i);
    int right = heap.getRightIndex(i);
    // find minimum among i, left, right
    int minIndex;
    if (left != 0 && arrays[heap[left]][0] < arrays[heap[i]][0]){
		 minIndex = left;
	}
    else minIndex = i;

    if (right != 0 && arrays[heap[right]][0] < arrays[heap[minIndex]][0]){
		 minIndex = right;
	}

    // switch the min index with the root node
    if (minIndex != i){
        int temp = heap[i];
        heap[i] = heap[minIndex];
        heap[minIndex] = temp;
        minHeapify(heap, minIndex, arrays);
    }
}


vector<int> mergeSortedArray(vector<vector<int>>& arrays){
	// make new array to hold the elements
	vector<int>* sortedArray = new vector<int>;

	// make heap to hold the array number representing the minimum element of 
	// each array
	MinHeap heap();

	// add array minimum elements and make the heap
	for(int i = 0; i<arrays.size(); i++){
		heap.add(i);
	}
	
	// modified to sort on element and not the index
	heap.minHeapifyModified(heap, 1, arrays);

	while (!heap.empty()){
		int index = heap.extractMin();
		sortedArray->insert(arrays[index][0]);
		if (!arrays[index].empty()){
			heap.add(index);
			arrays[index].remove(0);
		}
		heap.minHeapifyModified(heap, 1, arrays);
	}

	return &sortedArray;
}








