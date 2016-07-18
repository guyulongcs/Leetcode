#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int * a = new int[2*n+1];
        generateParenthesisFunc(res, a, n, 0, 0, 0);
        delete a;
        
        return res;
        
    }
    
    void generateParenthesisFunc(vector<string>& res, int * a, int n, int index, int left, int right) {
        if(index >= 2*n) {
            string str = "";
            for (int i=0; i < 2*n; i++) {
                str += a[i];
            }
            res.push_back(str);
        }
        
        if(left < n) {
            a[index] = '(';
            generateParenthesisFunc(res, a, n, index+1, left+1, right);
        }
        if(right < left) {
            a[index] = ')';
            generateParenthesisFunc(res, a, n, index+1, left, right+1);
        }
    }
};

int main() {
    Solution s = Solution();
    
    int a[] = {3,4,5,6,7};
    
    vector<string> res =s.generateParenthesis(3);
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    
    
    //cout << res << endl;
}

