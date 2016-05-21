/* stores data in mildly ordered fashion
 *
 * advantages:
 *   - saves memory
 *   - fast access
 *   - easy to swap elements by themselves
 *   - 
 */

class VectorHeap{
	vector<int> v;
	
	int size(){ return v.size(); }
	
	// a heap is a near-perfect binary tree; therefore the parent is simply
	// half the index of the child
	int parent(int i){ return ((i+1)/2-1); }
	int left(int i){ return (2*(i+1))-1; }
	int right(int i){ return (2*(i+1)+1)-1; }
	
	// O(1)
	int maximum();
	
	int extractMax();

	void insert(int x)

	void increaseKey(int i, int k)

	// assumes subtrees at left(i) and right(i) are max heaps, but value at i
	// may be smaller than children
	// 
	// O(lg n)
	void maxHeapify(int i);
	
	// O(n)
	void buildMaxHeap();
}

void VectorHeap::maxHeapify(int i){
	int l = left(i);
	int r = right(i);
	if (l>self->size()) return;
	if (r>self->size()){
		if (v[l]>v[i]){
			temp = v[i];
			v[i] = v[l];
			v[l] = temp;
		}
		return;
	}
	
	// find largest among i and its children
	if (v[i] > max(v[l], v[r])) return;
	int largest = v[l]>v[r]?l:r;

	// swap i with largest
	int temp = v[i];
	v[i] = v[largest];
	v[largest] = temp;

	maxHeapify(largest);
}

// O(n) because most of the heap heights are small and therefore do not take
// O(lg n) time to run maxHeapify
void VectorHeap::buildMaxHeap{
	for (i = size()/2; i>=0; i--){
		maxHeapify(i);
}

int VectorHeap::maximum(){
	if (self->size()==0) throw -1;
	else return v[0];
}

int VectorHeap::extractMax(){
	if (self->size()==0) throw -1;
	max = v[0];
	v[0] = v[v.size()-1];
	v.pop_back();
	maxHeapify(0);
	return max;
}

void VectorHeap::increaseKey(int i, int key){
	if (key<v[i]) throw -1;
	v[i] = key;
	while (i>0 && v[parent(i)] < v[i]){
		int temp = v[parent(i)];
		v[parent(i)] = v[i];
		v[i] = temp;
		i = parent(i);
	}
}

void VectorHeap::insert(int key){
	v.push_back(INT_MIN);
	increaseKey(v.size()-1, key);
}

