/* finds the largest rectangular area that fits underneath a histogram
 *
 */

#include <stack>
#include <iostream>
#include <vector>

using namespace std;

int findLargestRect(vector<int> hist){
    
    int histSize = hist.size();
    
    // 2 base cases, after which we can assume
    if (histSize == 0) return 0;
    if (histSize == 1) return hist[0];
    
    // keep a stack on which we push the index of the histogram heights; also,
	// push the first element index (0)
    stack<int> stk;
    stk.push[0];
    
    // variable to store largest area
    int maxArea = 0;
    
    // loop through the histogram, starting at 1
    for (int i = 1; i < histSize; i++){

        // if the next element is smaller than the element at the top of the
		// stack, pop numbers until it is bigger;
        // 
        // while we pop them, we also calculate the area that can be gained if
		// we use the popped item fully
        while (hist[i] >= hist[stk.top()]) {
            // from the perspective of the popped element, at this point, we
			// know that the next smaller height is going to be hist[i]; since
			// if a smaller one had occured before then we would have popped
			// this element already
            // 
            // the previous smaller height is going to be the previous element
			// in the stack; since if there was a size in between the two then
			// it would be pushed between the two in the stack; therefore, we
			// can easily calculate the area of the desired rectangle
            
            int idx = stk.pop();
            int area = hist[idx] * ((i-1) - (stk.top()));
            if (area > maxArea) maxArea = area;
        }
        
        // if the next element is bigger than the top of the stack, push it to
		// the top; thus, the stack is maintained as a list of ascending numbers
        stk.push(i);
    }
    return maxArea;
}


int main(){

    return 0;
}
