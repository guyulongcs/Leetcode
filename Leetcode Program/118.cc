#include <iostream>
//#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>
#include <map>


using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vv;
        
        if(numRows == 0)
            return vv;
        
        vector<int> v(1,1);
        vv.push_back(v);
        
        if(numRows == 1)
            return vv;
        
        for(int i=2; i <= numRows; i++) {
            vector<int> vn;
            
            vn.push_back(1);
            for(int j=0; j+1 < v.size(); j++) {
                vn.push_back(v[j]+v[j+1]);
            }
            vn.push_back(1);
            vv.push_back(vn);
            v=vn;
        }
        
        return vv;
    }
    
    void printVV(vector<vector<int>> & vv) {
        for(int i=0; i < vv.size(); i++) {
            printV(vv[i]);
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

    Solution s;


    vector<vector<int>> res = s.generate(4);
    s.printVV(res);
    
    return 0;
}
