#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        map<string, int> mapWordCnt;
        vector2Map(words, mapWordCnt);
        int N=(int)s.length();
        if(N == 0 || words.size() == 0) {
            return res;
        }
        
        int wordLen = (int)words[0].length();
        int wordLenTotal = wordLen * (int)words.size();

        for(int i=0; i + wordLenTotal <= N; i++) {
            bool flag = isValidAllWord(s, i, mapWordCnt, wordLen, wordLenTotal);
            if(flag) {
                res.push_back(i);
            }
        }
        return res;
    }
    
    bool isValidAllWord(string & s, int pos, map<string, int> & mapWordCnt, int wordLen, int wordLenTotal) {
        map<string, int> mapWordCntCur;
        int i;
        for( i=pos; i < pos + wordLenTotal;i+=wordLen) {
            string cur = s.substr(i, wordLen);
            if(mapWordCnt.count(cur) == 0) {
                return false;
            }
            if(mapWordCntCur.count(cur) == 0) {
                mapWordCntCur[cur] = 0;
            }
            mapWordCntCur[cur]++;
            if(mapWordCntCur[cur] > mapWordCnt[cur]) {
                return false;
            }
        }
        return (i == pos + wordLenTotal);
    }
    
       void vector2Map(vector<string>& words, map<string, int> & mapWordCnt) {

        for(int i=0; i < words.size(); i++) {
            if(mapWordCnt.find(words[i]) == mapWordCnt.end()) {
                mapWordCnt[words[i]]=0;
            }
            mapWordCnt[words[i]]++;
        }
    }
    
    void printV(vector<int> & v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
};


int main() {
    Solution sol = Solution();
    
    string s;
    vector<string> words;
    
    s = "barfoothefoobarman";
    words = {"foo", "bar"};
    
    
    vector<int> res=sol.findSubstring(s, words);
    sol.printV(res);

    return 0;
}
