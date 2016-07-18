#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <algorithm>



using namespace std;

class Solution {
public:
    
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> map;
        unordered_map<string, char> map2;
        
        bool flag = true;
        int i=0;
        int j=0;
        for(; flag && i < pattern.length(); i++) {
            char pch = pattern[i];
            string word;
            for(; j < str.length(); j++) {
//                cout << "str[j]:" << str[j] << endl;
                if(str[j] != ' ') {
                    word += str[j];
                }
                else {
                    j++;
                    break;
                }
            }
            
//            cout << "pch:" << pch << ", word:" << word << endl;
            if(map.find(pch) == map.end()) {
                if(map2.find(word) == map2.end()) {
                    map[pch] = word;
                    map2[word] = pch;
                }
                else {
                    flag = false;
                    break;
                }
            }
            else {
                if(map[pch] != word) {
                    flag = false;
                    break;
                }
            }
            if(j == str.length()) {
                i++;
                break;
            }
        }
        bool flagRes=false;
//        cout << "flag:" << flag << endl;
//        cout << "i:" << i << "/" << pattern.length() << endl;
//        cout << "j:" << j << "/" << str.length() << endl;

        if(flag && (i == pattern.length()) && (j == str.length())) {
            flagRes = true;
        }
        return flagRes;
    }
    
};


int main() {
    

    Solution s;
    vector<int> v({1,2,3});
    
    string pattern="abba";
    string str = "dog dog dog dog";
    bool res= s.wordPattern(pattern, str);
    cout << res << endl;
    
    
    return 0;
}

