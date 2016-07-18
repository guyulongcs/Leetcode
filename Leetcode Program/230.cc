#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        
        int lc = treeNodeNum(root->left);
        
        if(lc < k-1) {
            res = kthSmallest(root->right, k-(lc+1));
        }
        else if(lc == k-1) {
            res = root->val;
        }
        else {
            res = kthSmallest(root->left, k);
        }
        
        return res;
    }
    
    int treeNodeNum(TreeNode * root) {
        if(root == NULL)
            return 0;
        int ln = treeNodeNum(root->left);
        int rn = treeNodeNum(root->right);
        int res = ln + rn + 1;
        return res;
    }
};

int main() {
    Solution s = Solution();
    TreeNode * T = new TreeNode(2);
    T->left = new TreeNode(1);
    T->right = new TreeNode(3);
    
    
    int res = 0;
    res = s.kthSmallest(T, 3);
    
    cout << res << endl;
}

