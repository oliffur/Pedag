/* returns a vector of all subsets of a given array
 * 
 * can be done recursively and nonrecursively
 */

#include <iostream>
#include <vector>

using namespace std;

// nonrecursively, using a bitmap
vector< vector<int> >* findSubsetsNR(vector<int>& array){
    vector< vector<int> >* subsets = new vector< vector<int> >;
	
	// loop from 0 to 2^n - 1
    for (int i = 0; i<pow(2,array.size());i++){
		// create a temporary integer to store the bitmap, and create a
		// temporary vector which we will add to the subsets list
        int temp = i;
        vector<int> tempVec;
		
		// if the next bit from the right is 1, add the corresponding element; 
		// otherwise, skip it
        for (int j = 0; j<array.size(); j++){
            if (temp%2) tempVec.push_back(set[j]);
			// remove the bit from the right by dividing our bitmap by 2
            temp = temp/2;
        }

		// add the vector we created to the list of subsets
        subsets->push_back(tempVec);
    }
	
    return subsets;
}

// recursively
vector< vector<int> >* findSubsetsR(vector<int>& array){
	vector< vector<int> >* subsets = new vector< vector<int> >;

	sort(array);

	// small case
	if (array.size()==0) return subsets;
	
	// we construct subsets in increasing order of largest element; we first
	// construct the subsets with largest element the first element, then the
	// second element, etc.
	for (int i = 0; i<array.size(); i++){
		// create a temporary vector, in which we will store all subsets of
		// size i
		vector< vector<int> >* tempVec = new vector< vector<int> >;
		
		// add all subsets already accounted for to the temporary array, then
		// add the current element
		for (int j = 0; j<subsets->size; j++) tempVec->emplace(subsets[j]);
		for (int j = 0; j<tempVec->size; j++) tempVec[j].push_back(array[i]);

		// add the singleton set
		vector<int> singleton {i};
		tempVec->emplace(singleton);

		// put everything in the temporary vector into the final list
		for (int j = 0; j<tempVec.size(); j++) subsets->emplace(tempVec[j]);
	}

	// add empty vector
	vector<int> empty;
	subsets->emplace(empty);

	return subsets;
}

