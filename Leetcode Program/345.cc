#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Solution {
public:
    
    string reverseVowels(string s) {
        
        string res=s;

        int N = s.length();
        if(N <= 1)
            return res;
        
        vector<char> vowels({'a', 'e', 'i', 'o', 'u'});
        unordered_set<char> vSet(vowels.begin(), vowels.end());

        
        int f=0;
        int e=N-1;
        while(true) {
//            cout << res[f] << "\t" << res[e] << endl;
            while(f < N && !isVowel(vSet, res[f]))
                  f++;
            while(e >= 0 && !isVowel(vSet, res[e]))
                  e--;
            if(f >= N || e < 0 || f >= e)
                  break;
            swap(res[f], res[e]);
            f++;
            e--;
        }
        return res;
    }
    
    bool isVowel( unordered_set<char> vSet, char ch) {
        ch = tolower(ch);
        return (vSet.find(ch) != vSet.end());
    }
};


int main() {
    

    Solution s;
    string s1="aA";
    string s2="def";
    
    vector< vector<char> > v;
    string res = s.reverseVowels(s1);
    cout << res << endl;
    
    
    return 0;
}

