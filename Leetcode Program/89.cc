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
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        for(int i=0; i<n;i++){
            int highest = 1<<i;
            int len = result.size();
            for(int i=len -1; i>=0; i--){
                result.push_back(highest+result[i]);
            }
        }  
        return result;
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


    vector<int> res = s.grayCode(2);
    s.printV(res);
    
    return 0;
}
