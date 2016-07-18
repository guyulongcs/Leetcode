#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdlib>


using namespace std;

class Solution {
public:
    

    void nextPermutation(vector<int>& s) {
        bool flag = true;
        int n=s.size();
        int i= 0;
        int j=0;
        for( i=n-2; i>=0; i--) {
            if(s[i] < s[i+1])
                break;
        }
        if(i < 0) {
            reverse(s.begin(), s.end());
            return;
        }
        
        for( j=n-1; j>=0; j--) {
            if(s[j] > s[i])
                break;
        }
        swap(s[i], s[j]);
        reverse(s.begin()+ i+1, s.end());

        
    }
    
    void printVec(vector<int> & v) {
        cout << "vec..." << endl;
        for(int j=0; j < v.size(); j++) {
            cout << v[j] << "\t";
        }
        cout << endl;
    }
    void printVecVec( vector< vector<int> > & vv) {
        
        for(int i=0; i < vv.size(); i++ ) {
            for(int j=0; j < vv[i].size(); j++) {
                cout << vv[i][j] << "\t";
            }
            cout << endl;
        }
        
    }
    
};


int main() {


    Solution s;
    vector<int> v({1,2,3});

    s.nextPermutation(v);
    s.printVec(v);


    return 0;
}

