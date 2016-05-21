/* given an array of non-negative integers, you are initially positioned at the
 * first index of the array; each element in the array represents your maximum
 * jump length at that position
 *
 */

#include <iostream>
#include <vector>
#include <iterator>

using namespace std;


int findMinJumps(vector<int> jumpArray){
    // save the size of the array
    int arrSize = jumpArray.size();
    
    // if the array is empty, return 0
    if (arrSize == 0) return 0;
    
    // keeps track of the min jumps required to get to each index position
    vector<int> minJumpArray(arrSize, -1);
    
    // initiate the first number in this array at 0
    minJumpArray[0] = 0;
    
    // loop through the array
    for (int i = 0; i<arrSize; i++){
        // if we cannot reach this point, return -1
        if (minJumpArray[i] == -1){
            return -1;
        }
        else{
            // update min jump table:
            // 
            // start at the farthest jump possible using current cell, but cap
			// it at the max index; loop down until you hit i again
            // 
            // update all -1s (meaning indices that haven't been filled out yet)
			// to 1 more than the current minJumpArray value
            for (int j = min(i+jumpArray[i],arrSize -1); j>i; j--){
                // if we hit a cell that has already been filled out, no need
				// to go further; break the loop
                if (minJumpArray[j] != -1){
                    break;
                }
                else{
                    minJumpArray[j] = minJumpArray[i] + 1;
                }
            }
        }
    }
    return minJumpArray[arrSize-1];
}

int main(){
    vector<int> jumpArray = {2,3,1,1,4,1,2,3,4,2,3,1,1,1,1,1,1,1,1};
    cout << findMinJumps(jumpArray) << endl;
    return 0;
}

