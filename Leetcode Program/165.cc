#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1;
        vector<int> v2;
        
        splitNum(version1, v1);
        splitNum(version2, v2);
        
//        printVector(v1);
//        printVector(v2);
        
        if(isGreatThan(v1, v2))
            return 1;
        else if(isGreatThan(v2, v1))
            return -1;
        else
            return 0;
    }
    
    
    void printVector(vector<int> v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    bool isGreatThan(vector<int>& v1, vector<int>& v2) {
        bool flag = false;
        int i=0;
        int N1=v1.size();
        int N2= v2.size();
        while(true) {
            if(i >= N1 || i >= N2) {
                break;
            }
            if(v1[i] < v2[i]) {
                flag = false;
                break;
            }
            else if(v1[i] > v2[i]) {
                flag = true;
                break;
            }
            else {
                i++;
            }
            
        }
        if(i == N2 && N1 > N2) {
            while(i < N1) {
                if(v1[i] > 0) {
                    flag = true;
                    break;
                }
                i++;
            }
        }
        
        
        return flag;
    }
    
    
    void splitNum(string & s, vector<int> & v, char splitCh='.') {
//        cout << s << endl;
        
        int N = s.length();
        int i=0;
        
        int num =0;
        for(int i=0; i < N; i++) {
            char ch = s[i];
            if(ch == splitCh) {
                v.push_back(num);
                num = 0;
            }
            else {
                int cur = ch-'0';
                num = num * 10 + cur;
            }
        }
        if(num >= 0) {
            v.push_back(num);
        }
            
    }
};


int main() {

    Solution s;
  
    string v1= "1.0";
    string v2 = "1";
    
    int res = s.compareVersion(v1, v2);
    
    cout << res << endl;

    return 0;
}

