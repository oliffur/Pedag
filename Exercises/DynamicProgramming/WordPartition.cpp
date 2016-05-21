#include <iostream>
#include <vector>
#include <string>

using namespace std;

void dfs(const vector<string>& wordbank, int end, \
  vector<string>& result, vector<string>& temp){

vector<string> wordPartition(string s, unordered_set<string>& dict){
	// wordbank[i]: all words ending at i
	vector< vector<string> > wordbank(s.size()+1, nullptr);
	wordbank[0] = new vector<string>;

	for (int i = 0; i<s.size(); i++){
		if (wordbank[i] == nullptr) continue;

		for (string word:dict){
			int len = word.size();

			// check to see if the word is possible from i
			int end = i + len;
			if (end>s.size()) continue;

			// if the substring from i matches the word, add the word to the
			//
			if (s.substring(i,end) == word){
				if (wordbank[end] == nullptr){
					wordbank[end] = new vector<string>;
				}
				wordbank[end].insert(word);
			}
		}
	}
	
	// result array that holds all valid results
	vector<string> result = new vector<string>;
	if (wordbank[s.size()] == nullptr) return result;
	
	// temp array that holds one particular result, in reverse order
	vector<string> temp = new vector<string>;
	dfs(wordbank, s.size(), result, temp);

	return result;
}

void dfs(const vector<string>& wordbank, int end, \
  vector<string>& result, vector<string>& temp){
    // if we have no letters left, make the concatenated string and add it to 
	// the result array
    if (end <= 0){
		string path = temp[temp.size()-1];
		for (int i = temp.size()-2; i>=0; i--){
			path += " " + temp[i];
		}

		result.add(path);
		return;
	}

	// for each string that ends at the end, add the string to temp and then
	// recurse / continue along the dfs
	for (string str:wordbank[end]){
		temp.add(str);
		dfs(dp, end-str.size(), result, temp);
		temp.remove(temp.size()-1);
	}
}
