/* given strings s and t, finds the number of distinct subsequences of s that
 * are equal to t; a subsequence is any string formed by deleting characters
 * from a base string
 *
 */

#include <iostream>
#include <string>

// proceed by dynamic programming. Let w(i,j) be the number of subsequences of
// s(0,i) equal to t(0,j); then,
// 
// if s[i] == t[j], w(i,j) = w(i-1,j-1) + w(i-1, j)
// else, w(i,j) = w(i-1, j)
int subsequences(string s, string t){
	// we need a dp array of s.size()+1 x t.size()+1 because the empty string
	// is our base case and counts as index 0
	int dp[s.size()+1][t.size()+1];
	
	// the empty string can only be achieved by deleting all characters
	for(int i = 0; i < s.size(); i++) dp[i][0] = 1;

	for(int i = 1; i <= s.size(); i++){
		for(int j = 1; j <= t.size(); j++){
			if (s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j] dp[i-1][j-1];
			else dp[i][j] = table[i-1][j];
		}
	}
	
	return dp[s.size()][t.size()];
}

