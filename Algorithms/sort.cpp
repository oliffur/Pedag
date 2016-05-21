#include <iostream>
#include <vector>
#include <heap.h>

using namespace std;

void swap(vector<int>& v, int one, int two){
	int temp = v[one];
	v[one] = v[two];
	v[two] = temp;
}

void quicksort(vector<int>& v, int start, int fin){
	int left = start;
	int right = fin;
	if (left<right){
		right--;
		while (left < right){
			if (v[left] <= v[fin]) left++;
			else{
				if (v[right] >= v[fin]) right--;
				else swap(v,left, right);
			}
		}
		if (v[left]>v[fin]) swap(v,left,fin);
		else{
			left++;
			swap(v,left,fin);
		}

		quicksort(v,start,left-1);
		quicksort(v,left+1,fin);
	}
}

void quicksort(vector<int>& v){
	if (!v.size()) return;
	quicksort(v,0,v.size()-1);
}

vector<int> heapsort(heap& h){
	vector<int> sorted;
	h.buildMaxHeap();
	for (int i = h.size()-1; i>=0; i--){
		sorted.push_back(h[1]);
		h[1] = h[i];
		h.pop();
		h.maxHeapify(1);
	}
}
		
		



int main(){
	vector<int> v{4,1,4,3,25,5,3,6,2,3,5,4,3,2,5};
	quicksort(v);
	for (auto i : v) cout << i << " ";
}
