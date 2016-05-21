/* there is a vector of children, and each child has a rating; you must give
 * candies to all the children such that (1) each child must have at least one
 * candy, and (2) children with higher ratings get more than their neighbors
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findCandies(vector<int> rtgs){
    
    int rtgSize = rtgs.size();
    
    // small size case
    if (rtgSize == 0) return 0;
    if (rtgSize == 1) return 1;
    
    vector<int> candies(rtgSize, 0);
    
    candies[0] = 1;
    
    // if bigger than previous element, set to prev+1; if smaller, set to 1
    // 
    // creates a bunch of 1's for descending sequences, but otherwise correct;
    // gives the necessary minimum, but is not sufficient
    for (int i = 1; i < rtgSize; i++){
        if (rtgs[i]>rtgs[i-1]){
            candies[i] = candies[i-1] + 1;
        }
        else{
            candies[i] = 1;
        }
    }
    
    // loop through the other way and fix any errors
    for (int i = rtgSize-2; i>=0; i--){
        if (rtgs[i]>rtgs[i+1]){
            // need max here because of necessary condition from previous loop
            candies[i] = max(candies[i], candies[i+1] + 1);
        }
    }
    
    // print out the sum
    return accumulate(candies.begin(), candies.end())
}
