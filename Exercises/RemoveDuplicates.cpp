/* allows up to k occurences of an item; after that, removes duplicates from a
 * sorted array
 */

#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

void removeDuplicates(vector<int>& myVec, int k){
   	// count for counting up to k (duplicate values)
   	int count = 1;

	// fast pointer; scans ahead for duplicates
    int fastPtr = 1;

	// slow pointer; lags behind and records array without duplicates
    int indexOld = 1;

	int vecSize = myVec.size();

    for (int i = 1; i < vecSize; i++){
		// if the previous element is not the same as the current element
        if (myVec[i]!=myVec[i-1]){
			// reset counter
            count = 1;

			// record current fastptr position at the slowptr mark
            myVec[slowPtr] = myVec[fastPtr];
            slowPtr++;
            fastPtr++;
        }
        else{
            // if we have reached the max for the current value, only increment
			// the fast pointer
			if (count==k){
                fastPtr++;
            }
			// otherwise, increment the count as well as both pointers and
			// update the value at the slow pointer
            else {
                count++;
                myVec[slowPtr] = myVec[fastPtr];
                slowPtr++;
                fastPtr++;
            }
        }
    }
	// erase unnecessary elements
    myVec.erase(myVec.begin()+indexOld, myVec.end());
}

int main(){
    vector<int> myVec = {1,1,1,1,1,2,2,2,2,2,2,3,3,3,3,4,5,5,6,6,6,7,7,8,8,8,8};
    removeDuplicates(myVec, 3);
    copy(myVec.begin(), myVec.end(), ostream_iterator<int>(cout, " "));
    return 0;
}
