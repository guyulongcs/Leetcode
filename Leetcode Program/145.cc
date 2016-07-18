#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root == NULL)
            return v;
        stack<TreeNode * > s;
        
        TreeNode * T= root;
        s.push(root);
        TreeNode * pre = NULL;
        while(!s.empty()) {
            T=s.top();
            
            if((T->left == NULL && T->right == NULL) || (pre != NULL && (T->left == pre || T->right == pre))) {
                v.push_back(T->val);
                s.pop();
            }
            else {
                if(T->right != NULL) {
                    s.push(T->right);
                }
                if(T->left != NULL) {
                    s.push(T->left);
                }
            }
            pre = T;
            
            
        }
        
        return v;
    }
    
    vector<int> postorderTraversal_reverse(TreeNode* root) {
        vector<int> v;
        if(root == NULL)
            return v;
        stack<TreeNode * > s;
        
        TreeNode * T= root;
        s.push(root);
        while(!s.empty()) {
            T=s.top();
            v.push_back(T->val);
            s.pop();
            if(T->left != NULL) {
                s.push(T->left);
            }
            if(T->right != NULL) {
                s.push(T->right);
            }
            
        }
        reverse(v.begin(), v.end());
        return v;
    }
};


int main() {

    Solution s;

    vector<int> v({0,1,2});
    TreeNode * T;
    T=new TreeNode(1);
    T->left = new TreeNode(2);
    T->right = new TreeNode(3);
    T->left->left = new TreeNode(4);


    vector<int> res = s.postorderTraversal(T);

    for(int i=0; i < res.size(); i++) {
        cout << res[i] << "\t";
    }
    cout << endl;

    return 0;
}

