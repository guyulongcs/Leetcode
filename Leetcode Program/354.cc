#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <deque>
#include <algorithm>
#include <queue>

using namespace std;


struct Item {
    int w;
    int h;
    Item(){}
    Item(int pw=0, int ph = 0): w(pw), h(ph){}
};

bool Cmp(const Item & item1, const Item & item2) {
    if(item1.w < item2.w)
        return true;
    else if(item1.w > item2.w)
        return false;
    else {
        if(item1.h < item2.h)
            return true;
        else
            return false;
    }
    
}
bool CompW(const Item & item1, const Item & item2) {
    return item1.w < item2.w;
}

bool CompH(const Item & item1, const Item & item2) {
    return item1.h < item2.h;
}

bool CompWH(const Item & item1, const Item & item2) {
    return item1.w < item2.w && item1.h < item2.h;
}

struct CmpW {
    bool operator()(const Item & item1, const Item & item2) {
        return CompW(item1, item2);
    }
};

struct CmpH {
    bool operator()(const Item & item1, const Item & item2) {
        return CompH(item1, item2);
    }
};

class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        vector<Item> vi;
        getVecItem(envelopes, vi);
        int cnt=0;
        int maxCnt = 0;
        sort(vi.begin(), vi.end(), Cmp);
        
        int N = vi.size();
        solve(vi, N, 0, vi.size()-1, cnt, maxCnt);
        return maxCnt;
        
    }
    
    void getVecItem(vector<pair<int, int>>& envelopes, vector<Item> & vi) {
        for(int i=0; i < envelopes.size(); i++) {
            Item item(envelopes[i].first, envelopes[i].second);
            vi.push_back(item);
        }
    }
    
    void solve(vector<Item>& vi, int N, int s, int e, int cnt, int & maxCnt) {
        vector<int> v(N, 1);
        for(int i=s; i <= e; i++) {
            v[i] = 1;
            for(int j=s; j < i; j++) {
                if(CompWH(vi[j], vi[i])) {
                    v[i] = max(v[i], v[j]+1);
                }
            }
            maxCnt = max(v[i], maxCnt);
        }
            
    }
    
};



int main() {
    Solution s= Solution();
    vector<pair<int, int>> v;
    v.push_back(pair<int,int>(2,3));
    v.push_back(pair<int,int>(4,5));
    v.push_back(pair<int,int>(5,4));
    v.push_back(pair<int,int>(6,5));
    v.push_back(pair<int,int>(7,6));
    
    
    
    int res = s.maxEnvelopes(v);
    cout << res << endl;
    return 0;
}

