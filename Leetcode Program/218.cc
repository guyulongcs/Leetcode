nclude <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>

#include <algorithm>

using namespace std;



class Solution {
public:
    vector<pair<int, int>> getSkyline(vector< vector<int> >& buildings) {
        
        vector< pair<int,int> > res;
        int N = buildings.size();
        if(N == 0) {
            return res;
        }
        
        vector< pair<int,int> > height;
        for(int i=0; i < N; i++) {
            vector<int> line = buildings[i];
            height.push_back(pair<int, int>(line[0], -line[2]));
            height.push_back(pair<int, int>(line[1], line[2]));
        }
        
        sort(height.begin(), height.end());
        
        multiset<int> heap;
        heap.insert(0);
        int pre=0;
        int cur;
        for(auto it:height) {
            int hei =it.second;
            if(hei < 0) {
                heap.insert(-hei);
            }
            else {
                heap.erase(heap.find(hei));
            }
            cur = *heap.rbegin();
            if(cur != pre) {
                res.push_back({it.first, cur});
                pre = cur;
            }
        }
        
        
        return res;
    }
};

int main() {
     Solution s;

     vector<vector<int>> vv;
     vv.push_back(vector<int>{2, 9, 10});
     vv.push_back(vector<int>{3, 7, 15});
     vv.push_back(vector<int>{5, 12, 12});
     vv.push_back(vector<int>{15, 20, 10});
     vv.push_back(vector<int>{19, 24, 8});

     vector<pair<int, int>> res = s.getSkyline(vv);

     for(int i=0; i < res.size(); i++)  {
         cout << res[i].first << "\t" << res[i].second << endl;
     }
     return 0;
 }

