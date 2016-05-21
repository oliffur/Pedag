/* returns the longest palindromic substring within a string
 * 
 * 
 * 
 */

#include <iostream>
#include <string>

using namespace std;

// method that takes a string and two indices, i and j; there are two cases:
//
// case 1: i = j
//   returns longest palindrome which is centered at index i
// case 2: i = j-1
//   returns longest palindrome centered around [i,j]; it must be that 
//   str[i] = str[j]
string findPalinFromCenter(string str, int i, int j);

// finds the maximum palindromic substring
string findPalinSub(string str){
	// string to store the maximum substring
    string maxSubstring;

	// store the size of the underlying string
    int strSize = str.size();

    for (int i = 0; i<strSize; i++){
		// find the longest palindrome centered at the current index or the
		// current index and its successor
        string temp = findPalinFromCenter(str, i, i);
        string temp2 = findPalinFromCenter(str, i, i+1);
        
		// if either of those strings is larger than the maximum so far,
		// replace the maximum so far
        if (temp.size()>maxSubstring.size()) maxSubstring = temp;
        if (temp2.size()>maxSubstring.size()) maxSubstring = temp2;
    }

    return maxSubstring;
}

string findPalinFromCenter(string str, int i, int j){
	// edge cases; return empty string
    if (str[i] != str[j] || j>=str.size()) return "";
	
	// while i and j are pointing to the same character
	while (str[i] == str[j]){
		// shift i and j out
        i--;
        j++;
		// if we have reached an edge, exit
        if (i<0 || j>= str.size()) break;
    }
    
	// we have gone one step too far! (because of the while loop)
	// take a step back in both directions and return substring
    return str.substr(i+1,(j-i-1));
}

int main(){
    
    cout << findPalinSub("gasdfabsefaasdfghjkllkjhgfdsagrwbbsdfa") << endl;
    return 0;
}
