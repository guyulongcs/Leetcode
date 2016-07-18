#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdlib>


using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode * p1=NULL;
        TreeNode * p2 = NULL;
        TreeNode * pre = NULL;
        inorder(root, p1, p2, pre);
        swap(p1->val, p2->val);
    }
    
    void inorder(TreeNode * root, TreeNode * & p1, TreeNode * & p2, TreeNode * & pre) {
        if(root->left) {
            inorder(root->left, p1, p2, pre);
        }
        if(pre != NULL && (root->val < pre->val)) {
            if(p1 == NULL) {
                p1 = pre;
            }
            p2 = root;
        }
        pre = root;
        if(root->right) {
            inorder(root->right, p1, p2, pre);
        }
    }
    
};


int main() {


    Solution s;
    vector<int> v({1,2,3});
    return 0;
}

