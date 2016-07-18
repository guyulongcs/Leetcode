#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector< vector<string> > groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mapVec = vector2MapVector(strs);
        vector< vector<string> > res;
        for(unordered_map<string, vector<string> >::iterator it = mapVec.begin(); it != mapVec.end(); it++ ) {
            vector<string> anagrams;
            vector<string> strVec = mapVec[it->first];
            sort(strVec.begin(), strVec.end());
            for(vector<string>::iterator its = strVec.begin(); its != strVec.end(); its++) {
                anagrams.push_back(*its);
            }
            res.push_back(anagrams);
        }
        return res;
    }
    
    unordered_map<int, int> vector2Map(vector<int>& nums) {
        unordered_map<int, int> mapCnt;
        for(int i=0; i < nums.size(); i++) {
            int num = nums[i];
            if(mapCnt.find(num) == mapCnt.end()) {
                mapCnt[num]=0;
            }
            mapCnt[num]++;
        }
        return mapCnt;
    }
    
    unordered_map<string, vector<string> > vector2MapVector(vector<string>& strs) {
        unordered_map<string, vector<string> > mapVec;
        for(int i=0; i < strs.size(); i++) {
            string str = strs[i];
            string strOrg = str;

            sort(str.begin(), str.end());
            
            cout << "\nsort" << endl;
            cout << strOrg << endl;
            cout << str << endl;
            
            if(mapVec.find(str) == mapVec.end()) {
                mapVec[str] = vector<string>();
            }
            mapVec[str].push_back(strOrg);
        }
        return mapVec;
    }
};

int main() {
    vector<string> v1({"ab", "ba", "c", "ab"});
   
    Solution s= Solution();
    vector< vector<string> >  v = s.groupAnagrams(v1);
    for(int i=0; i < v.size(); i++) {
        cout << v[i].size() << "\t";
        for(int j=0; j < v[i].size(); j++) {
            cout << v[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    
    
    return 0;
}

