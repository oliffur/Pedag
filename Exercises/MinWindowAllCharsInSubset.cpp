/* given a string s and a string t, finds the minimum window in s that contains
 * all the characters in t
 *
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string findWindow(string s, string sub){
    // map to store how many of each char is in the substring
    unordered_map<char, int> subMap;
    int subLen = sub.size();
    
    for (int i = 0; i<subLen; i++){
        subMap[sub[i]]++;
    }
    
    // map to store how many of each char is in the string, which we then use
	// to compare to the map for the substring
    unordered_map<char, int> map;
    int strLen = s.size();
    int count = 0;
    int begPtr = 0;
    int endPtr = 0;
    int minBeg = -1;
    int minEnd = s.size();
    
    while(endPtr < strLen){
        
        // if we are matching some character in the substring, increase that
		// respective char in the map and increase the count
        if (map[s[endPtr]] < subMap[s[endPtr]]){
            map[s[endPtr]]++;
            count++;
            
            cout << "hello" << endl;
        }
        // otherwise just increase that char in the map but do not increase the
		// count
        else{
            map[s[endPtr]]++;
        }
        // if we reach a point where we have matched all of the characters then
		// start moving the start pointer up as much as we can
        if (count==subLen){
            while (map[s[begPtr]]>subMap[s[begPtr]]){
                map[s[begPtr]]--;
                begPtr++;
            }
            // if the substring is smaller than the window, adjust the window
            if ((endPtr - begPtr + 1)<(minEnd - minBeg + 1)){
                minBeg = begPtr;
                minEnd = endPtr;
            }
            // move the start pointer up one more (to find the next window) and
			// adjust the map and the count accordingly
            map[s[begPtr]]--;
            begPtr++;
            count--;
        }
        // move up the end pointer
        endPtr++;
    }
    
    // if it is impossible, return empty string
    if (minBeg == -1) return "";
    // otherwise return the proper min window substring
    return s.substr(minBeg, minEnd - minBeg + 1);
}

int main(){
    string S = "ADOBECODEBANC";
    string T = "ABC";
    cout << findWindow(S,T) << endl;
    return 0;
}
