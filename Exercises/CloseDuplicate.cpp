/* Given an array of integers, find out whether there are two distinct indices 
 * i and j in the array such that the difference between nums[i] and nums[j] is
 * at most t and the difference between i and j is at most k.
 *
 */

#include <set>
#include <iostream>

using namespace std;

bool containsDup(vector<int>& vec, int diffIdx, int diffVal){
	// an ordered set implemented as a binary tree; it holds values that we add
	// one by one and removes values that are too far apart index-wise, and also
	// has a subset function that runs in O(set.size) time
	set<int> treeSet;

	for (int i = 0; i < vec.size(); i++){
		// get iterator for the lower/upper bounds from diffVal and vec[i]
		vector<int>::iterator flor = treeSet.lower_bound(vec[i] - diffVal);
		vector<int>::iterator ceil = treeSet.upper_bound(vec[i] + diffVal);
		
		// if the 2 iterators have something between them, return true
		if (flor != ceil) return true;

		// add the current value to the treeset, and remove the value that is
		// now out of the range index-wise
		treeSet.emplace(vec[i]);
		if (i>diffIdx) treeSet.erase(vec[i-diffIdx]);
	}

	return false;
}
