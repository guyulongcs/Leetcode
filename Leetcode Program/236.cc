#include <iostream>
#include <vector>
#include <string>
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
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        if(root == p || root == q)
            return root;
        TreeNode * left = lowestCommonAncestor(root->left, p, q);
        TreeNode * right = lowestCommonAncestor(root->right, p, q);
        if(left && right) {
            return root;
        }
        return left ? left : right;
        
    }
    
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        
    
        vector<TreeNode *> vp;
        vector<TreeNode *> vq;
        
        
        bool flag = false;
        vector<TreeNode *> v;
        dfs(root, p, v, flag, vp);
        
        flag = false;
        v.clear();
        dfs(root, q, v, flag, vq);
        
        TreeNode * T=NULL;
        
        int lp = vp.size();
        int lq = vq.size();
        
//        cout << lp << endl;
//        cout << lq << endl;
        
        int i;
        for(i=0; i < lp && i < lq; i++) {
//            cout << "vp:" << vp[i]->val << endl;
            if(vp[i] != vq[i])
                break;
        }
        if(i > 0)
            T = vp[i-1];
        else
            T = root;
        return T;
    }
    
    void dfs(TreeNode * root, TreeNode * p, vector<TreeNode *>& v, bool & flag,  vector<TreeNode *>& vp) {
        
        if(root == NULL) {
            return;
        }
        
        if(flag)
            return;
        v.push_back(root);
        if(root == p) {
            flag = true;
            vp = v;
            return;
        }
        
        dfs(root->left, p, v, flag, vp);
        dfs(root->right, p, v, flag, vp);
        v.pop_back();
    }
};

int main() {
    
    Solution s;
    
    
    TreeNode* root = new TreeNode(-1);
    root->left = new TreeNode(0);
    root->left->left = new TreeNode(-2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(8);
//    root->left->right->right = new TreeNode(4);
//    
    root->right = new TreeNode(3);
//    root->right->left = new TreeNode(0);
//    root->right->right = new TreeNode(8);
    
    TreeNode* p = root->left->left->left;
    TreeNode* q = root->left->right;
    TreeNode* c;
    
    string str = "";
    c= s.lowestCommonAncestor(root, p, q);
    cout << c->val <<endl;
    
    
    
    
    return 0;
}

