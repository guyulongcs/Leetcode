#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:

    int maximalRectangle(vector< vector<char> >& matrix) {
        if(matrix.size()==0 || matrix[0].size() == 0)
            return 0;
        int m = (int)matrix.size();
        int n = (int)matrix[0].size();
        
        int maxArea = 0;
        vector<int> vh(n, 0);
        for(int i=m-1; i >= 0; i--) {
            for(int j=0; j < n; j++) {
                char ch = matrix[i][j];
                if(ch == '0') {
                    vh[j] = 0;
                }
                else {
                    vh[j] = vh[j] + 1;
                }
            }
            //printVec(vh);
            int cur = largestRectangleArea(vh);
            maxArea = max(maxArea, cur);
        }
        
        return maxArea;
    }
    
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
    
    void printVec(vector<int> & v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    
};

int main() {
    Solution s;
    int res = 0;


    vector< vector<char> > matrix(2, vector<char>(2,'1'));
    matrix[0][1] = matrix[1][1] = '0';


    res =s.maximalRectangle(matrix);
    cout << res << endl;
    return 0;
}

