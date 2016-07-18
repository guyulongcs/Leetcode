#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>

using namespace std;

const int WHITE = 1;
const int GRAY = 2;
const int BLACK = 3;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode * head = NULL;
        TreeNode * tail = NULL;
        flattern_tree(root, head, tail);
        
    }
    
    void flattern_tree(TreeNode* root, TreeNode * & head, TreeNode * & tail) {
        TreeNode * lh = NULL;
        TreeNode * lt = NULL;
        TreeNode * rh = NULL;
        TreeNode * rt = NULL;
        
        if(root == NULL) {
            head = root;
            tail = root;
            return;
        }
        
        if(root->left == NULL && root->right == NULL) {
            head = root;
            tail = root;
            return;
        }
        
        flattern_tree(root->left, lh, lt);
        flattern_tree(root->right, rh, rt);
        if(lh != NULL) {
            root->right = lh;
            if(lt != NULL)
                lt->right = rh;
            tail = lt;
        }
        if(rt != NULL) {
            tail = rt;
        }
        root->left = NULL;
        head = root;
    }
    
};

int main() {

    Solution s;

    TreeNode * r = new TreeNode(1);
    r->left = new TreeNode(2);
    r->right = new TreeNode(5);
    
    r->left->left = new TreeNode(3);
    r->left->right = new TreeNode(4);
//    r->left->left->left = new TreeNode(5);
    r->right->right = new TreeNode(6);
//

    
    s.flatten(r);
//    cout << r->val << endl;
//    cout << r->right->val << endl;
    TreeNode *  p = r;
    while(p!=NULL) {
        cout << p->val << endl;

//        if(p->left == NULL) {
//            cout << "p->left == NULL" << endl;
//        }
//        else {
//            cout << "p->left != NULL:" << p->left->val << endl;
//        }
        p = p->right;
    }

    return 0;
}
