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

class BSTIterator {
public:

    stack<TreeNode *> s;
public:
    BSTIterator(TreeNode *root) {
        TreeNode * p=root;
        
        while(p) {
            s.push(p);
            p=p->left;
        }
    }
    void printStack(stack<TreeNode *> s) {
        cout << "stack:" ;
        while(!s.empty()) {
            cout << (s.top())->val << "\t";
            s.pop();
        }
        cout << endl;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (!s.empty());
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode * p = s.top();
        s.pop();
        int res = p->val;
        p = p->right;
        while(p) {
            s.push(p);
            p=p->left;
        }
        return res;
    }
};

int main() {
    
    TreeNode * T = new TreeNode(3);
    T->left = new TreeNode(1);
    T->left->left = new TreeNode(0);
    T->left->right = new TreeNode(2);
    T->right = new TreeNode(6);
    T->right->left = new TreeNode(5);
    T->right->right = new TreeNode(7);
    
    BSTIterator it(T);
    
    int i=0;
    while(it.hasNext()) {
        int num = it.next();
        cout << "num:" << num << endl;
        i++;
    }
    return 0;
}

