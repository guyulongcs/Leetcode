nclude <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector< vector<int> > combine(int n, int k) {
        vector< vector<int> > vv;
        vector<int> v;
        
        dfs(1, n, k, v, vv);
        return vv;
    }
    
    void dfs(int s, int e, int k, vector<int> v, vector< vector<int> >& vv) {
        
        if(k == 0) {
            vv.push_back(v);
            return;
        }
        
        if(s > e) {
            return;
        }
        
        for(int i=s; i <= e; i++) {
            vector<int> vc = v;
            vc.push_back(i);
            dfs(i+1, e, k-1, vc, vv);
        }
    }
    
    void printV(vector<int> v) {

        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    
    void printVV(vector< vector<int> > vv) {
        for(int i=0; i < vv.size(); i++) {
            printV(vv[i]);
        }
    }
};

int main() {

    Solution s;
   

    vector< vector<int> > vv = s.combine(4,2);
    s.printVV(vv);

    return 0;
}

