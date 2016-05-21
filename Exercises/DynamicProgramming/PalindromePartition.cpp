/* given a string, partitions the string into a minimal number of palindromes
 *
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int minPartition(string s){
	int len = s.size();
	
	// palin[i][j]: true if [i,...,j] is a palindrome
	bool palin[len][len];

	// cut[i]: minimum number of cuts to partion [0,...,i] into palindromes	
	int cut[len];
	
	// loop through till len, and at each iteration calculate cut[i]
	for (int i = 0; i < len; i++){
		cut[i] = i; // set to maximum possible # of cut

		// loop through the string up to i, looking for a potential to cut
		for (int j = 0; j <= i; j++){
			// if [i...j] is a palindrome, we can cut at i
			if (s[j] == s[i] && (j-i <= 1 || palin[j+1][i-1])){
				palin[j][i] = true;

				// if we cut, we reduce to the same problem with j-1, which we
				// have already solved; only cut if we improve on cut[i]
				if (j>0) cut[i] = min(cut[i], cut[j-1] + 1);
				else cut[i] = 0; // no need to cut if [0,...,i] is a palindrome
			}
		}
	}
	return cut[len-1];
}
