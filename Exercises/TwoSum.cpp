/* finds out whether there exist two numbers that add to a specific target
 *
 */

#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

bool twoSum(vector<int>& vec, int target){
	// create an unordered set; once we see a number, we will add target-number
	// to the set; if number is already in the set then we have found two
	// numbers summing to target
    unordered_set<int> set;
    for (int i = 0; i<vec.size(); i++){
        if (set.count(vec[i])) return true;
        set.emplace(target - vec[i]);
    }
    return false;
}

int main(){
	vector<int> vec = {2,6,9,11,12,20};
	cout << twoSum(vec, 19) << endl;
	cout << twoSum(vec, 32) << endl;
}
