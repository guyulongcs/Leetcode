#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num;
        unordered_map<int, int> map1 = vector2Map(nums1);
        unordered_map<int, int> map2 = vector2Map(nums2);
        for(unordered_map<int, int>::iterator it = map1.begin(); it != map1.end(); it++) {
            int key1 = it->first;
            if(map2.find(key1) == map2.end())
                continue;
            int value1 = it->second;
            int value2 = map2[key1];
            int value = min(value1, value2);
            for(int i=0; i<value;i++) {
                num.push_back(key1);
            }
        }
        
        return num;
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
};

int main() {
    vector<int> v1({1,2,2,1});
    vector<int> v2({2,2});
    Solution s= Solution();
    vector<int> v = s.intersect(v1, v2);
    for(int i=0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout << endl;
    
    
    return 0;
}

