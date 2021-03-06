/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool flag = true;
        if(p == NULL || q == NULL) {
            flag = (p==NULL) && (q==NULL);
        }
        else if( p -> val != q -> val) {
            flag = false;
        }
        else {
            flag = isSameTree( p -> left, q -> left) && isSameTree( p -> right, q -> right);
        }
        return flag;
    }
};
