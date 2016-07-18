#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstdlib>
#include <map>
#include <cmath>
using namespace std;


class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        
        int res = 0;
        stack<int> s;
        
        heights.push_back(0);
        int N = heights.size();
        for(int i=0; i < N; i++)  {
            if(s.empty() || heights[i] >= heights[s.top()]) {
                s.push(i);
            }
            else {
                while(!s.empty() && heights[i] < heights[s.top()]) {
                    //                    cout << "i:" << i << endl;
                    int cur = s.top();
                    s.pop();
                    
                    int leftLen = (s.empty() ? (cur+1) : (cur - s.top()));
                    int rightLen = i-cur-1;
                    int left = leftLen * heights[cur];
                    int right = rightLen * heights[cur];
                    int area = left + right;
                    res = max(res, area);
                }
                s.push(i);
            }
        }
        
        heights.pop_back();
        return res;
    }
    
    int largestRectangleArea_dp(vector<int>& heights) {
        int N = heights.size();
        int res = 0;
        vector<int> h(N+1, INT32_MAX);
        for(int i=1; i <= N; i ++) {
            h[i-1] = INT32_MAX;
            for(int j=i; j <= N; j++) {
                h[j] = min(h[j-1], heights[j]);
                int area = (j-i+1) * h[j];
                res = max(res, area);
            }
        }
        return res;
    }
    
    void printV(vector<char> & v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    void printVV( vector< vector<char> >  & vv) {
        for(int i=0; i < vv.size(); i++) {
            printV(vv[i]);
        }
    }
};


int main() {

    Solution s;

    vector<int> v({2,1,2});
    int res = s.largestRectangleArea(v);
    cout << res << endl;

    return 0;
    
}
