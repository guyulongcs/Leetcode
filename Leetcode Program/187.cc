#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        
        unordered_map<string, int> map;
        int N=s.length();
        const int Len=10;
        for(int i=0; i < N; i++) {
            string strsub = s.substr(i, Len);
            if(map.find(strsub) == map.end()) {
                map[strsub] = 0;
            }
            map[strsub]++;
        }
        
        for(unordered_map<string,int>::iterator it = map.begin(); it != map.end(); it++) {
            int cnt = it->second;
            if(cnt > 1) {
                string str = it->first;
                res.push_back(str);
            }
        }
        
        return res;
    }
};

int main() {
    Solution s= Solution();
    
    vector<string> v1({"ab", "ba", "c", "ab"});
   
    string str="AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    
    vector< string >  v = s.findRepeatedDnaSequences(str);
    
    for(int i=0; i < v.size(); i++) {
        cout << v[i]<< "\t";
    }
    cout << endl;
    
    
    return 0;
}

