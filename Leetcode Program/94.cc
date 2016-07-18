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
    vector<int> inorderTraversal(TreeNode* root) {
         vector<int> res;
        
        stack<TreeNode * > s;
        TreeNode * p = root;
    
        if(root != NULL) {
            while(p != NULL || s.empty() == false) {
                
                while(p != NULL) {
                    s.push(p);
                    p = p -> left;
                }
                
                if(s.empty() == false) {
                    p = s.top();
                    res.push_back(p->val);
                    s.pop();
                    p = p -> right;
                }
            }
        }
        
        return res;
    }
};
