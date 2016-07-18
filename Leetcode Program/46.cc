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
    
    
    vector< vector<int> > permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        
        vector< vector<int> > vv;
        vector<int> v=nums;
        vv.push_back(v);
        while(true) {
            bool flag = getPermNextVec(v);
            
            if(flag == false)
                break;
            //            printVec(v);
            vv.push_back(v);
            
        }
        return vv;
    }
    
    
    vector< vector<int> > permute_r(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
//        printVec(nums);
        vector< vector<int> > vv = permute_rec(nums, 0, nums.size()-1);
        
        
        return vv;
    }
    
    vector< vector<int> > permute_rec(vector<int>& nums, int begin, int end) {
//        cout << "begin, end:" << begin << "\t" << end << endl;
        vector< vector<int> > vv;
        if(begin == end) {
            vv.push_back(vector<int>(1, nums[begin]));
            return vv;
        }
        
        vector< vector<int> > vvpre= permute_rec(nums, begin, end-1);
//        cout << "vvpre:" << vvpre.size() << endl;
        for(int i=0; i < vvpre.size(); i++) {
            vector<int> v = vvpre[i];
//            printVec(v);
            int N = v.size()+1;
            for(int j=0; j < N; j++) {
                vector<int> v2(v);
                
                v2.insert(v2.begin()+j, nums[end]);
                vv.push_back(v2);
            }
            
        }
        return vv;
        
    }
    
    bool getPermNextVec(vector<int>& s) {
        bool flag = true;
        int n=s.size();
        int i= 0;
        int j=0;
        for( i=n-2; i>=0; i--) {
            if(s[i] < s[i+1])
                break;
        }
        if(i < 0)
            return false;
        
        
        for( j=n-1; j>=0; j--) {
            if(s[j] > s[i])
                break;
        }
        swap(s[i], s[j]);
        reverse(s.begin()+ i+1, s.end());
        
        return flag;
        
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
    vector<int> v({3,2,1});
    
    vector< vector<int> > vv= s.permute(v);
    s.printVecVec(vv);


    return 0;
}

