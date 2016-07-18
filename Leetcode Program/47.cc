#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <cstdlib>


using namespace std;


struct Cmp {
    bool operator()(const vector<int> & v1, const vector<int> & v2) {
        bool flag = false;
        
        if(v1.size() < v2.size()) {
            return true;
        }
        
        for(int i=0; i < v1.size(); i++) {
            if(v1[i] < v2[i]) {
                flag = true;
                break;
            }
            else if(v1[i] > v2[i]) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};

class Solution {
public:
    
    vector< vector<int> > permute_base(vector<int>& nums) {
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
    
    vector< vector<int> > removeDuplicateVV(vector< vector<int> > & vv) {
        vector< vector<int> > res;
        set<vector<int>, Cmp> s;
        for(int i=0; i < vv.size(); i++) {
            s.insert(vv[i]);
        }
        for(auto it=s.begin(); it != s.end(); it++) {
            res.push_back(*it);
        }
        
        return res;
    }
    
    vector< vector<int> > permuteUnique(vector<int>& nums) {
        vector< vector<int> > vv = permute(nums);
        //vv = removeDuplicateVV(vv);
        return vv;
    }
    
    
    
    vector< vector<int> > permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        //        printVec(nums);
        vector< vector<int> > vv;
        //vv = permute_rec(nums, 0, nums.size()-1);
        //vv = permute_base(nums);
        
        dfs(nums, 0, nums.size()-1, vv);
        
        
        
        return vv;
    }
    
    bool isNoSwap(vector<int>& nums, int begin, int k) {
        bool flag = false;
        if(k > begin){
            for(int l=k-1; l >= begin; l--) {
                if(nums[k] == nums[l]) {
                    flag =true;
                    break;
                }
            }
        }
        return flag;
    
    }
    void dfs(vector<int>& nums, int begin, int end, vector< vector<int> > & vv) {
        
        if(begin >= end) {
            vector<int> v;
            vv.push_back(nums);
            return;
        }
        int i=1;
//        while(begin+i <= end && nums[begin+i] == nums[begin])
//            i++;
        
        for(int k=begin; k <= end; k++) {
//            if(k != begin && nums[k] == nums[begin])
//                continue;
            if(isNoSwap(nums, begin, k))
                continue;
            
            swap(nums[begin], nums[k]);
            dfs(nums, begin+1, end, vv);
            swap(nums[begin], nums[k]);
        }
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
        cout << vv.size() << endl;
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
    vector<int> v({1,1, 2,2,3,3});

    vector< vector<int> > vv= s.permuteUnique(v);
    s.printVecVec(vv);


    return 0;
}

