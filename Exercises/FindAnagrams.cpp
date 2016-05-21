/* finds the number of anagrams for a given string within a vector of strings
 * 
 */

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int findAnagrams(vector<string> vec, string s){
	// match sorted string with sorted strings in the vector
    s.sort();
	// count for number of matching strings
    int count = 0;
    for (int i = 0; i < vec.size(); i++) vec[i].sort();
    
    for (int i = 0; i < vec.size(); i++) if (vec[i] == s) count++;
    return count;
}
