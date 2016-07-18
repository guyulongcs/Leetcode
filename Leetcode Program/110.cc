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

struct QueueNode {
    TreeNode * t;
    int level;
    QueueNode(TreeNode * tn, int l) : t(tn), level(l) {}
};

class Tree {
    TreeNode * T;
    Tree() {
        T = NULL;
    }
    void createTree(vector<string> v) {
        
    }
};
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL)
            return true;
        
        int h=0;
        return postOrder(root, h);
    }
    
    bool postOrder(TreeNode* root, int & h) {
        if(root == NULL) {
            h = 0;
            return true;
        }
        
        
        if(root->left == NULL && root->right == NULL) {
            h=1;
            return true;
        }
        
        int hl = 0;
        int hr = 0;
        
        bool flag = true;
        bool fl = postOrder(root->left, hl);
        bool fr = postOrder(root->right, hr);
        if((fl && fr) == false)
            return false;
        if(abs(hl-hr) > 1) {
            flag = false;
        }
        else {
            flag = true;
            h = max(hl, hr) + 1;
        }
        
        return flag;
    }
    
    
};

class Vector {
public:
    static void printVector(vector<int> v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    
    static void printVV(vector< vector<int>> vv) {
        for(int i=0; i < vv.size(); i++) {
            printVector(vv[i]);
        }
        
    }
    
};

int main() {

    Solution s;
    TreeNode * root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    bool flag = s.isBalanced(root);

    cout << flag << endl;

    return 0;
}

