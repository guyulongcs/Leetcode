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
    vector< vector<int> > levelOrder(TreeNode* root) {
        vector< vector<int> > vv;
        
        if(root == NULL)
            return vv;
        
        int level = 1;
        
        queue<QueueNode> q;
        q.push(QueueNode(root, level));
        
        vector<int> v;
        
        while(!q.empty()) {
            QueueNode node = q.front();
            int nlevel = node.level;
            
//            cout << "val:" << (node.t)->val << endl;
            if(nlevel != level) {
                level = nlevel;
                vv.push_back(v);
                v.clear();
            }
            v.push_back((node.t)->val);
            
            TreeNode * T = node.t;
            if(T->left != NULL) {
                q.push(QueueNode(T->left, nlevel + 1));
            }
            if(T->right != NULL) {
                q.push(QueueNode(T->right, nlevel + 1));
            }
            
            q.pop();
        }
        if(v.size() > 0) {
            vv.push_back(v);
        }
        return vv;
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
    
    vector< vector<int> >  vv = s.levelOrder(root);
    
    Vector::printVV(vv);
    
    return 0;
}

