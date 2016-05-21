nclude <string>
#include <iostream>

using namespace std;

bool compareStrings(string target, int offset, int length){
    for (int i = 0; i<length; i++){
        if (target[i] != target[i+offset]){
            return false;
        }
    }
    return true;
}

int computePreTable(string target, int index){
    for (int i = index-1; i>0; i--){
        if (compareStrings(target, index-i, i)){
            return i;
        }
    }
}

bool doesOccur(string baseString, string target){
    int targetLength = target.length();
    int preTable[targetLength];
    for (int i = 0; i<targetLength; i++){
        preTable[i] = computePreTable(target, i);
    }
}
