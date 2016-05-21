#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

struct TrieNode{
    char c;
    bool isLeaf = false;
    unordered_map<char, TrieNode*> children;
    TrieNode(char c);
};

TrieNode::TrieNode(char c){
    this->c = c;
}

class Trie{
public:
    Trie(char c);
    void insert(string word);
    bool search(string word);
    bool startsWith(string prefix);
    TrieNode* seekNode(string s);
private:
    TrieNode* root;
};

Trie::Trie(char c){
    this->root = new TrieNode(c);
}

void Trie::insert(string word){
    TrieNode* currNode = this->root;
    for (int i = 0; i < word.size(); i++){
        if (!currNode->children[word[i]]){
            currNode->children[word[i]] = new TrieNode(word[i]);
        }
        currNode = currNode->children[word[i]];
    }
    if (currNode->isLeaf) cout << "error: word already exists" << endl;
    else currNode->isLeaf = true;
}

TrieNode* Trie::seekNode(string s){
    TrieNode* currNode = this->root;
    for (int i = 0; i < s.size(); i++){
        if (!currNode->children[s[i]]){
            return nullptr;
        }
        currNode = currNode->children[s[i]];
    }
    return currNode;
}

bool Trie::startsWith(string prefix){
    if (this->seekNode(prefix)) return true;
    else return false;
}

bool Trie::search(string prefix){
    TrieNode* node = this->seekNode(prefix);
    if (!node) return false;
    else{
        if (node->isLeaf) return true;
        else return false;
    }
}
