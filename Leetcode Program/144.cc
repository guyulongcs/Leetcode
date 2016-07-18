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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        
        stack<TreeNode * > s;
        
        if(root != NULL) {
            s.push(root);
            while( s.size() > 0) {
                TreeNode * curNode = s.top();
                res.push_back(curNode -> val);
                s.pop();
                if(curNode -> right != NULL) {
                    s.push(curNode->right);
                }
                if(curNode -> left != NULL) {
                    s.push(curNode -> left);
                }
            }
        }
        
        return res;
        
    }
};
