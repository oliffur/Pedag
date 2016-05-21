/* finds the kth order statistic in an array
 *
 */

#include <iostream>
#include <vector>

int quickSelect(vector<int>& vec, int k){
	return getK(vec, 0, vec.size()-1, k);
}

int getK(vector<int>& vec, int begIdx, int endIdx, int k){
	if (begIdx == endIdx){
		if (k!=1) return NULL;
		return vec[begIdx];
	}
	int pivot = vec[endIdx];
	int left = begIdx;
	int right = endIdx-1;
	while(left<right){
		while (vec[left] < pivot) left++;
		while (vec[right] >= pivot) right--;
		swap(vec, left, right);
	}
	if (vec[left]<pivot) left++;

	swap(vec, left, endIdx);

	if (k>left) return getK(vec, left, endIdx, k-left);
	else return getK(vec, begIdx, left, k);
}
