/* finds the longest substring of a given string with no repeated characters 
 *
 */

#include <unordered_map>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

string findLongestSubstringNoRepeat(string s){
	
	// base case for short strings
	if (s.length() <= 2) return s;
	
	// variable to store longest length and indices
	int maxLen = 0;
	int begIdx = 0;
	
	// stores current two chars that the fn is investigating and also their
	// positions (indices) within the string
	unordered_map<char,int> map;

	// insert the first two characters of the string into the map
	map.emplace(s[0],0);
	map.emplace(s[1],1);
	
	// sweeper variable that removes letters from the map once we find a repeat
	int sweeper = 0;

	// loop over the rest of the string
	for (int i = 2; i<s.length(); i++){
		char c = s[i];
		
		if (!map.count(c)){
			// if c is not already in the map put c and its index in the map
			map.emplace(c,i);
		}
		else {
			// if c is already inside the map and if the max length is smaller
			// than the current max length, update it
			if (map.size() > maxLen){
				maxLen = map.size();
				begIdx = sweeper;
			}
			
			// move to the last place where the repeated element was, removing
			// elements from the map along the way
			while (s[sweeper] != c){
				map.erase(s[sweeper]);
				sweeper++;
			}

			// update the map and the sweeper
			map[c]=i;
			sweeper++;
		}
	}
	
	return s.substr(begIdx, maxLen);
}



int main(){
	
	cout << findLongestSubstringNoRepeat("geeksforgeeks") << endl;
}
