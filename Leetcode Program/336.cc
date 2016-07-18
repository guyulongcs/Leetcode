#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        //res = palindromePairsNorm(words);
        res = palindromePairsHash(words);
        return res;
    }
    
    vector<vector<int>> palindromePairsNorm(vector<string>& words) {
        int N = words.size();
        
        vector<vector<int>> res;
        vector<vector<bool>> flagPalin(N, vector<bool>(N, false));
        for(int i=0; i < N; i++) {
            for(int j=0; j < N; j++) {
                if(i == j) {
                    continue;
                }
                bool flag = false;
                if(i > j && (words[i].length() == words[j].length())) {
                    flag = flagPalin[j][i];
                }
                else {
                    flag = isPalin(words[i], words[j]);
                    flagPalin[i][j] = flag;
                }
                if(flag) {
                    vector<int> v;
                    v.push_back(i);
                    v.push_back(j);
                    res.push_back(v);
                }
            }
        }
        
        return res;
    }
    
    vector<vector<int>> palindromePairsHash(vector<string>& words) {
        vector<vector<int>> res;
        int N = (int)words.size();
        unordered_map<string, int> map;
        
        for(int i=0; i < N; i++) {
            map[words[i]] = i;
        }
        
        for(int i=0; i < N; i++) {
            string word = words[i];
            int len = word.length();
            string wordReverse = getStrReverse(word);
            
            //self method
            if(len != 0 && isPalinStr(word) && isMapHasStr(map, "")) {
                int j = map[""];
                addPair(i, j, res);
                addPair(j, i, res);
            }
            
            //reverse method
            if(isMapHasStr(map, wordReverse)) {
                int j = map[wordReverse];
                if(i < j) {
                    addPair(i, j, res);
                    addPair(j, i, res);
                }
            }
            
            //split method
            for(int k=1; k < len; k++) {
                string left = word.substr(0, k);
                string right = word.substr(k);
                string leftReverse = getStrReverse(left);
                string rightReverse = getStrReverse(right);
                if(isPalinStr(left) && isMapHasStr(map, rightReverse)) {
                    int j = map[rightReverse];
                    addPair(j, i, res);
                }
                if(isPalinStr(right) && isMapHasStr(map, leftReverse)) {
                    int j = map[leftReverse];
                    addPair(i, j, res);
                }
            }
        }
        
        return res;
    }
    
    string getStrReverse(string & str) {
        string res = str;
        reverse(res.begin(), res.end());
        return res;
    }
                    
    bool isMapHasStr(unordered_map<string, int> & map, string str) {
        return (map.find(str) != map.end());
    }
    
    void addPair(int i, int j, vector<vector<int>> & res) {
        vector<int> v;
        v.push_back(i);
        v.push_back(j);
        res.push_back(v);
    }
    
    bool isPalinStr(string & s) {
        bool flag = true;
        int N = (int)s.length();
        int i=0;
        int j= N-1;
        while(i < j) {
            if(s[i] != s[j]) {
                flag = false;
                break;
            }
            i++;
            j--;
        }
        return flag;
    }
    bool isPalin(string & s1, string & s2) {
        string s = s1 + s2;
        return isPalinStr(s);
        
    }
    
    void printV(vector<int> & v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    
    void printVV(vector<vector<int>> & vv) {
        cout << "\n\n";
        for(int i=0; i < vv.size(); i++) {
            printV(vv[i]);
        }
    }
    
};


int main() {
    Solution s;
    
    vector<vector<int>> res;
    
    vector<string> words;
    
    words = vector<string>{"bat", "tab", "cat"};
    res = s.palindromePairs(words);
    s.printVV(res);
    
    words = vector<string>{"abcd", "dcba", "lls", "s", "sssll"};
    res = s.palindromePairs(words);
    s.printVV(res);
    
    return 0;
}

