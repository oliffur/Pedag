/* given array, 'rotates' it by k places
 * 
 */

#include <vector>
#include <iostream>
using namespace std;

// reverses array from index start to index end
void reverseArray(vector<int>& myVector, int start, int end){
	// loop until the middle
	for(int i = 0; i < (end - start + 1)/2 ; i++){
	      // swap elements from either side
	      int temp = myVector[start + i];
		  myVector[start + i] = myVector[end - i];
		  myVector[end-i] = temp;
	}
}

int main(){
     const int kSize = 20;
     const int kRotation = 83;
     if (kSize == 0){
         return 0;
     }
     vector<int> myVector(kSize);
     // set up vector
     for (int i = 0; i<kSize; i++){
         myVector[i] = i;
     }
     // print vector
     copy(myVector.begin();myVector.end();ostream_iterator<int>(cout," "));

	// rotation by rotationSize is the same as rotating by kRotation%kSize
    // to do this, we reverse first from index 0 to kSize - kRotation%kSize,
    // then we rotate kRotation%kSize to kSize, and then we rotate the entire
    // vector; this is effectively the same as rotation
    reverseArray(myVector,0,kSize - (kRotation%kSize) - 1);
    reverseArray(myVector,kSize - (kRotation%kSize), kSize - 1);
    reverseArray(myVector,0,kSize - 1);

	// print array
    copy(myVector.begin();myVector.end();ostream_iterator<int>(cout," "));

	return 0;
}
