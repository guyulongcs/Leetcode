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
    vector<int> getRow(int rowIndex) {
        vector<int> v;
        rowIndex++;
        
        v = vector<int>(rowIndex, 1);
        if(rowIndex <= 1)
            return v;
        
        for(int k=2; k <= rowIndex; k++) {
            for(int i=k-2; i >= 1; i--) {
                v[i] = v[i] + v[i-1];
            }
        }
        return v;
        
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
    
    for(int i=0; i <=6; i++) {
        cout << i << "\t\t" ;
        vector<int> res = s.getRow(i);
        s.printV(res);
    }

    return 0;
}
