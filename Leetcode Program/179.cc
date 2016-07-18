#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;


bool Cmp(const string & s1, const string & s2) {
    
    bool flag = false;
    int l1=s1.length();
    int l2 = s2.length();
    
    if(l1 != l2) {
        return Cmp(s1+s2, s2+s1);
    }

    
    int i=0;
    
    bool flagAllEqual = true;
    for(i=0; i < l1;i++) {
        if(s1[i] > s2[i]) {
            flag = true;
            flagAllEqual = false;
            break;
        }
        else if(s1[i] < s2[i]) {
            flag = false;
            flagAllEqual= false;
            break;
        }
    }

    return flag;
}


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        vector<string> vs;
        for(int i=0; i < nums.size(); i++) {
            vs.push_back(to_string(nums[i]));
        }
        
        sort(vs.begin(), vs.end(), Cmp);
        
        
        
        for(int i=0; i < vs.size(); i++) {
            //cout << vs[i] << "\t";
            res = res + vs[i];
        }
        
        res = removeZero(res);
        return res;
        
    }
    
    string removeZero(string  res) {
        string s = res;
        int N = res.length();
        if(N <= 1)
            return res;
        int i=0;
        while(res[i] == '0')
            i++;
        if(i == N)
            s = "0";
        else
            s = s.substr(i);
        return s;
    }
};

int main() {


    Solution s;
    vector<int> v({824,938,1399,5607,6973,5703,9609,4398,8247});
    
    int n=1;

    string res= s.largestNumber(v);
    cout << res << endl;

//    
//    cout << Cmp("3", "30")<< endl;
//    cout << Cmp("30", "3")<< endl;
//    cout << Cmp("9", "30")<< endl;
    
    
    return 0;
}


