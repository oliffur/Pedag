/* edit distance is a way of quantifying how dissimilar two strings are by
 * counting the minimum number of operations required to transform one string
 * into the other; viable operations are replace, delete, and insert
 *
 */

#include <iostream>
#include <string>

using namespace std;

// approach: let dp[i][j] be the edit distance between s(0,i-1) and t(0,j-1):
// let x = s[i-1], y = t[j-1]; then,
//
// if x==y, dp[i][j] = dp[i-1][j-1]
// if x!=y and...
//     we insert y into s, dp[i][j] = dp[i][j-1] + 1
//     we delete x from s, dp[i][j] = dp[i-1][j] + 1
//     replace x with y in x, then dp[i][j] = dp[i-1][j-1]+1
int editDist(string s, string t){
	int ssize = s.size();
	int tsize = t.size();

	// add 1 to sizes because the empty string is the base case
	int dp[ssize+1][tsize+1];
	
	// i deletions for the following
	for(int i = 0; i<=ssize; i++) dp[i][0] = i;
	for(int i = 0; i<=tsize; i++) dp[0][i] = i;

	for(int i = 0; i < ssize; i++){
		for(int j = 0; j < tsize; j++){
			if (s[i]==t[j]) dp[i+1][j+1] = dp[i][j];
			else dp[i+1][j+1] = min(dp[i][j], dp[i-1][j], dp[i][j-1]) + 1;
		}
	}
	return dp[ssize][tsize];
}

