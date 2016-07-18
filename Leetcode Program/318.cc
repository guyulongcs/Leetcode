#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;




class Solution {
public:
    vector<int> arrWordHash;


int maxProduct(vector<string>& words) {
    mapVectorString(words);
    int res = calMaxProduct2(words);
    return res;
}

void mapVectorString(vector<string>& words) {
    for(int i=0; i < (int)words.size(); i++) {
        int hashValue = 0;
        for(int j=0; j < (int)words[i].length(); j++) {
            hashValue |= (1 << (words[i][j]-'a'));
        }
        arrWordHash.push_back(hashValue);
    }
}


int calMaxProduct2(vector<string>& words) {
    int maxRes = 0;
    for(int i=0; i < (int)words.size(); i++) {
        for(int j=i+1; j < (int)words.size(); j++) {
            
            int maxValue = strProduct(words, i, j);
            if(maxValue > maxRes) {
                maxRes = maxValue;
            }
        }
    }
    return maxRes;
}

int strProduct(vector<string> & words, int i, int j) {
    int res = 0;
    
    if(strHasCommonLetter(words, i, j) == false) {
        res = words[i].length() * words[j].length();
    }
    
    return res;
}

bool strHasCommonLetter(vector<string> & words, int i, int j) {
    bool flag = false;
    if(true){
        int h1 = arrWordHash[i];
        int h2 = arrWordHash[j];
        int tmp = h1 & h2;
        if(tmp > 0) {
            flag = true;
        }
    }
    return flag;
}

};
