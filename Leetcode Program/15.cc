#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;


struct Cmp {
    bool operator()(const vector<int> & v1, const vector<int> & v2) {
        bool flag = false;
        if(v1.size() < v2.size())
            return true;
        else if(v1.size() > v2.size())
            return false;
        
        int N = v1.size();
    
        if(N == 0) {
            return false;
        }
        
        int i=0;
        for(i=0; i < N; i++) {
            if(v1[i] > v2[i]) {
                flag = false;
                break;
            }
            if(v1[i] < v2[i]) {
                flag = true;
                break;
            }
            
        }
        if(i == N) {
            flag = false;
        }
        
        
        return flag;
    }
};

struct Cmp2 {
    bool operator() (const int & n1, const int & n2) {
        bool flag=false;
        flag = n1 < n2;
        return flag;
        
    }
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> vv;
        int N = nums.size();
        if( N < 3)
            return vv;
        
        
        int minDiff = INT32_MAX;
        int i=0;
        int res = 0;
        
        int target = 0;
        
        for(i=0; i <= N-3; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            twoSum(nums, i+1, N-1, target-nums[i], nums[i], vv);
            //mergeRes(vvtwo, nums[i], vv);
        }
        
        vector<vector<int>> vvNew;
        
        vvNew = vv;
        
//        printVV(vv);
        
//        cout << "removeDuplicatesVecVecInt" << endl;
        //removeDuplicatesVecVecInt(vv, vvNew);
        
        return vvNew;
    }
    
    void removeDuplicatesVecVecInt(vector<vector<int>> & vv, vector<vector<int>> & res) {
        set<vector<int>, Cmp> vecSet;
//        vector<int> v({-1,-1, 2});
//        vector<int> v2({-1,0,1});
//        vecSet.insert(v);
//        //
//        vecSet.insert(v2);
//        vecSet.insert(v);
        
        for(int i=0; i < vv.size(); i++) {
            vecSet.insert(vv[i]);
        }
        
        for(auto it = vecSet.begin(); it != vecSet.end(); it++) {
            res.push_back(*it);
        }
    }
    
    void mergeRes(vector<vector<int>> & vvtwo, int num, vector<vector<int>> & vv) {
        for(int i=0; i < vvtwo.size(); i++) {
            vector<int> vc = vvtwo[i];
            vc.insert(vc.begin(), num);
            vv.push_back(vc);
        }
    }
    
    void twoSum(vector<int>& nums, int s, int e, int target, int num, vector<vector<int>> & vv) {
        int i=s;
        int j=e;
        int minDiff = INT32_MAX;
        
        //vector<vector<int>> vv;
        int N = nums.size();
        
        int res= 0;
        while(i < j) {
            int cur = nums[i] + nums[j];
            if(cur == target) {
                vector<int> cur;
                cur.push_back(num);
                cur.push_back(nums[i]);
                cur.push_back(nums[j]);
                vv.push_back(cur);
                while(i < j && nums[i] == nums[i+1])
                    i++;
                while(j > i && nums[j] == nums[j-1])
                    j--;
                i++;
                j--;
            }
            else if(cur < target){
                i++;
            }
            else {
                j--;
            }
        }
        
        //return vv;
    }
    
    void mergeVV(vector<vector<int>> & vvnew, vector<vector<int>> & vv) {
        for(int i=0; i < vvnew.size(); i++) {
            vv.push_back(vvnew[i]);
        }
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
    vector<int> v({7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6});
    int n=0;

    vector<vector<int>> res= s.threeSum(v);
    s.printVV(res);
    
    
    return 0;
}


