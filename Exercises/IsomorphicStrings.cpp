/* tests if two strings are isomorphic, i.e. if there is a mapping of letters
 * that maps one string to the other; for example, 'wowza' and 'babel' are
 * isomorphic but 'foo' and 'bar' are not
 *
 */

#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

bool isIsomorphic(string firstString, string secondString){

	// if the two strings do not have the same length they cannot be isomorphic
	if (firstString.length() != secondString.length()){
		return false;
    }
	
	// insert elements of second string into hashmap, indexed by elements of
	// first string; if we hit a conflict, the strings cannot be isomorphic
	unordered_map<char, char> myMap;
	for (int i = 0; i < firstString.length(); i++){
		// if it does not already exist in the map, insert it
		if (!myMap.count(firstString[i])){
			myMap[firstString[i]] = secondString[i];
		}
		else{
			//if it is in the map, check if it matches
			if (myMap[firstString[i]] != secondString[i]){
				return false;
			}
		}
	}
	
	// if there is no conflict, the strings must be isomorphic
	return true;
}

int main(){
	cout << isIsomorphic("abc","abc") << endl;
	cout << isIsomorphic("babel","wowza") << endl;	
	cout << isIsomorphic("awefwawfefa","asdgg") << endl;					
	cout << isIsomorphic("","") << endl;				
	cout << isIsomorphic("","a") << endl;				
	cout << isIsomorphic("a","") << endl;	
	return 0;
}
