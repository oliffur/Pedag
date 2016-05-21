/* finds the median among 2 sorted arrays
 *
 */

#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;


int findMedian(const vector<int>& firstVector, const vector<int>& secondVector);

int findKth(int k, const vector<int>& one, const vector<int>& two,\
int oneL, int oneH, int twoL, int twoH){
	
	int oneS = oneH-oneL+1;
	int twoS = twoH-twoL+1;

	if (k == 1) return (one[oneL]<two[twoL] ? one[oneL]:two[twoL]);
	else if (k == oneS+twoS) return (one[oneH]>two[twoH] ? one[oneH]:two[twoH]);
	

	float ptile = ((double) k) / ((double) (oneS + twoS));
	int oneTab = (int) (ptile * oneS);
	int twoTab = k - oneTab;
	int oneLev = oneL + oneTab - 1;
	int twoLev = twoL + twoTab - 1;
	
	

	if (one[oneLev] > two[twoLev]){
		int diff = twoLev - twoL;
		oneH = oneLev;
		twoL = twoLev;
		cout << "1 " << k-diff << " $ " <<  oneL << " * " << oneH << " & " << twoL << " * " << twoH << endl;
		assert(oneL < oneH);
		return findKth(k-diff, one, two, oneL, oneH, twoL, twoH);
	}

	if (one[oneLev] <= two[twoLev]){
		int diff = oneLev - oneL;
		oneL = oneLev;
		twoH = twoLev;
		cout << "2 " << k-diff << " $ " << oneL << " * " << oneH << " & " << twoL << " * " << twoH << endl;
		assert(oneL<oneH);
		return findKth(k-diff, one, two, oneL, oneH, twoL, twoH);
	}
	
}

int main(){
	vector<int> vec1{1,4,5,7,8,9,14,15,17};
	vector<int> vec2{2,3,6,10,11,12,13,16,18,19,20};

	cout << findKth(12, vec1, vec2, 0, vec1.size()-1, 0, vec2.size()-1) << endl;

	return 0;
}
