#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    int maxPathSum(TreeNode* root) {
        int maxs=INT32_MIN;
        int s=0;
        int rmsingle=0;
        int rmdouble = 0;
        dfs(root, rmsingle, rmdouble, maxs);
        return maxs;
    }
    
    int dfs(TreeNode* root, int & msingle, int & mdouble, int & maxs) {
        if(root == NULL)
            return 0;
        
        int lmsingle = 0;
        int lmdouble = 0;
        int rmsingle = 0;
        int rmdouble = 0;
        
        int s1 = dfs(root->left, lmsingle, lmdouble, maxs);
        int s2 = dfs(root->right, rmsingle, rmdouble, maxs);
        
        int s = INT32_MIN;
        msingle = max(root->val, root->val + max(lmsingle, rmsingle));
        mdouble = root->val + lmsingle + rmsingle;
        
        s = max(msingle, mdouble);
        
        maxs = max(maxs, s);
        
        return s;
    }
};


int main() {

    Solution s;
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
//    root->right->left = new TreeNode(15);
//    root->right->right = new TreeNode(7);

    int res = s.maxPathSum(root);

    cout << res << endl;

    return 0;
}

