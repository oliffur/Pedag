/* given an array of n positive integers and some target, finds the minimal
 * length of a subarray of which the sum is greater than the target
 * 
 */

#include <iostream>
#include <vector>
#include <climits>
#include <iterator>

using namespace std;
    
int minSubArrayLen(vector<int>& myVec, int target){
    // base case
	if (myVec.size() == 0){
        return 0;
    }
    
    // left side of window
    int indexLeft = 0;
    
    // right side of window
    int indexRight = 0;
    
	// the sum inside the window
    int sumBetween = myVec[0];

	// the minimum length of the vector so far that
	// has a sum greater than the target
    int minSoFar = INT_MAX;

	// loop through the vector,
    while (indexRight < myVec.size()){
		// if the window sum is less than the target,
		// move the right pointer and therefore increase
		// the window sum
        if (sumBetween<target) {
            ++indexRight;
            sumBetween += myVec[indexRight];
        }
		// otherwise, if the subarray length is smaller
		// then keep track of its length; after that, move
		// the left pointer and decrement the window sum
        else{
            if (indexRight - indexLeft < minSoFar){
                minSoFar = indexRight - indexLeft;
            }
            ++indexLeft;
            sumBetween -= myVec[indexLeft];
        }
    }
    return minSoFar;
}


int main(){
    vector<int> myVec{1, 5, 6, 1, 2, 4,8 ,2,4,5,3,8,1,2,8,9,1,5,4,5,8};
    copy(myVec.begin(),myVec.end(),ostream_iterator<int>(cout, " "));
    cout << endl;
    cout << minSubArrayLen(myVec, 30) << endl;
}
