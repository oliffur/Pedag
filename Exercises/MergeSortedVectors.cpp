/* given two sorted integer arrays A and B, merge B into A as one sorted array
 *
 */

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

void mergeSortedArrays(vector<int>& firstVector, vector<int>& secondVector){
    // save down the sizes
    int firstSize = firstVector.size();
    int secondSize = secondVector.size();
    
    for (int i = 0; i<secondSize; i++){
        firstVector.push_back(secondVector[i]);
    }
    // have two indices that sweep through the two vectors, starting at the back
    int firstIndex = firstSize-1;
    int secondIndex = secondSize -1;

    // while there are still elements to be compared
    while (firstIndex>=0 && secondIndex>=0){
        // compare elements at the two indices; if one is larger, add it to the
        // end of the first list (master list)
        if (firstVector[firstIndex]>secondVector[secondIndex]){
            firstVector[firstIndex+secondIndex+1] = firstVector[firstIndex];
            --firstIndex;
        }
        else {
            firstVector[firstIndex + secondIndex + 1] = secondVector[secondIndex];
            --secondIndex;
        }
    }
}


int main(){
    vector<int> firstVector = {0,4,10,14,20,25,60,61,62,63,100};
    vector<int> secondVector= {1,4,8,11,13,17,27,37,47,57,67};
    mergeSortedArrays(firstVector,secondVector);
    copy(firstVector.begin(),firstVector.end(),ostream_iterator<int>(cout," "));
    return 0;
}

