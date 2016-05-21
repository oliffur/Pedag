#include <unordered_set>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;

int findConsecutiveChain(vector<int>& myVec){
    unordered_set<int> mySet;
    copy(myVec.begin(),myVec.end(),inserter(mySet, mySet.end()));
    int maxChainSoFar = 1;
    int maxChain, crawler;
    for (unordered_set<int>::iterator iter = mySet.begin(); iter != mySet.end(); iter++){
        maxChain = 1;
        crawler = 1;
        while(true){
            if (mySet.count((*iter)+crawler)){
                mySet.erase((*iter)+crawler);
                ++maxChain;
                ++crawler;
            }
            else break;
        }
        crawler = 1;
        while(true){
            if (mySet.count((*iter)-crawler)){
                mySet.erase((*iter)-crawler);
                ++maxChain;
                ++crawler;
            }
            else break;
        }
        if (maxChain > maxChainSoFar){
            maxChainSoFar = maxChain;
            cout << (*iter) << endl;
            cout << maxChain << endl;
        }
        cout << "loop cycle " << (*iter) << endl;
    }
    return maxChainSoFar;
}

int main(){
    vector<int> myVec{3,5,1,8,5,6,8,8,7,4,8,6,8,79,55,5,43,152,3,84,65,111,35,54,851,854,853,852,855,856,857,858,859,860};
    cout << findConsecutiveChain(myVec) << endl;
    
}
