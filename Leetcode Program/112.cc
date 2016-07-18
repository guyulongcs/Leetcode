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
    bool hasPathSum(TreeNode* root, int sum) {
        bool flag = dfs(root, sum, 0);
        return flag;
    }
    
    bool dfs(TreeNode* root, int sum, int s) {
        if(root == NULL)
            return false;
        
        s += root->val;
        
        if(root->left == NULL && root->right == NULL) {
            if(sum == s)
                return true;
        }
        
        bool flag1 = dfs(root->left, sum, s);
        if(flag1)
            return true;
        bool flag2 = dfs(root->right, sum, s);
        if(flag2)
            return true;

        return false;
    }
    
    int getNum(vector<int> v) {
        int res = 0;
        for(int i=0; i < v.size(); i++) {
            res = res * 10 + v[i];
        }
        return res;
    }
};


int main() {

    Solution s;
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
//    root->right->left = new TreeNode(15);
//    root->right->right = new TreeNode(7);

    bool res = s.hasPathSum(root, 5);

    cout << res << endl;

    return 0;
}

