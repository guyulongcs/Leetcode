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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int pVal = p->val;
        int qVal = q->val;
        
        int minVal = pVal;
        int maxVal = qVal;
        
        if(minVal > maxVal) {
            minVal = qVal;
            maxVal = pVal;
        }
        
        int rootVal = root->val;
        TreeNode * resultNode;
        if(rootVal > maxVal) {
            resultNode = this->lowestCommonAncestor(root->left, p, q);
        }
        else if(rootVal < minVal){
            resultNode = this->lowestCommonAncestor(root->right, p, q);
        }
        else {
            resultNode = root;
            
        }
        return resultNode;
    }
};
