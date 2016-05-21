/* finds the three numbers whose sum is closest to a given target
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int threeSum(vector<int>& vec, int target){
	
	// variable to keep track of the minimum difference so far
	int minSoFar;
	
	// sort our array
	vec.sort();

	int vecSize = vec.size();

	// i represents the first number
	for (int i = 0; i<vecSize; i++){
		// fixing the first number, j and k represent the second and third
		// number, which start from the left and the right, respectively
		int j = i+1;
		int k = vecSize-1;

		while (j<k){
			// if the diff is smaller than the min diff, update the min diff
			if (abs(target - vec[i] - vec[j] - vec[k]) < abs(minSoFar)){
				minSoFar = target - vec[i] - vec[j] - vec[k];
			}
			
			// if we are below the target, increment the left pointer
			// otherwise, decrement the right pointer
			if (target > vec[i] + vec[j] + vec[k]){
				j++;
			}
			else{
				k--;
			}
		}
	}
	return (target - minSoFar);
}
