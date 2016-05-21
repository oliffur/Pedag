// prints out all combinations of size r from set {1,...,n}

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

/* arr[]  ---> Input Array
   data[] ---> Temporary array to store current combination
   beg & end ---> Staring and Ending indexes in arr[]
   idx  ---> Current index in data[]
   r ---> Size of a combination to be printed */
void comb(vector<int>& arr, vector<int>& data, \
  int beg, int end, int idx, int r);
 
// The main function that prints all combinations of size r from array
void printCombs(vector<int>& arr, int r){
    // A temporary array to store all combination one by one
    vector<int> data(r,0);
    // Print all combination using temprary array 'data[]'
    combinationUtil(arr, data, 0, arr.size()-1, 0, r);
}
 
// basic idea is that we loop through arr, picking a first element; then, we
// recursively pick a random element further than that first element as a
// second element, and so on.
//
// this is achieved using recursion; data[] holds each combination as we
// recurse, and we increment idx by 1 until it reaches r, after which we know
// that we are done
void comb(vector<int>& arr, vector<int>& data, \
  int beg, int end, int idx, int r){
    // Current combination is ready to be printed, print it
    if (idx == r){
        for (int j=0; j<r; j++) cout << data[j] << " ";
        cout << endl;
        return;
    }

    // replace index with all possible elements. The condition for i makes sure
	// that including one element at index will make a combination with 
	// remaining elements at remaining positions
    for (int i=beg; i<=end && end-i+1 >= r-idx; i++){
        data[idx] = arr[i];
        comb(arr, data, i+1, end, idx+1, r);
    }
}
