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

 struct TreeLinkNode {
     int val;
     TreeLinkNode *left;
     TreeLinkNode *right;
     TreeLinkNode *next;
     TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };

struct QueueNode {
    TreeLinkNode * t;
    int level;
    QueueNode(TreeLinkNode * tn, int l) : t(tn), level(l) {}
};

class Solution {
public:
    void connect(TreeLinkNode* root) {
        
        if(root == NULL)
            return;
        
        int level = 1;
        
        queue<QueueNode> q;
        q.push(QueueNode(root, level));
        
        vector<QueueNode> v;
        
        while(!q.empty()) {
            QueueNode node = q.front();
            int nlevel = node.level;
            
            //            cout << "val:" << (node.t)->val << endl;
            if(nlevel != level) {
                level = nlevel;
                
                connectNext(v);
                v.clear();
            }
            v.push_back(node);
            
            TreeLinkNode * T = node.t;
            if(T->left != NULL) {
                q.push(QueueNode(T->left, nlevel + 1));
            }
            if(T->right != NULL) {
                q.push(QueueNode(T->right, nlevel + 1));
            }
            
            q.pop();
        }
        
        connectNext(v);
        
    }
    
    void connectNext(vector<QueueNode>& v) {
        if(v.size() == 0) {
            return;
        }
        int N = v.size();
        for(int i=0; i < N-1; i++) {
            v[i].t->next = v[i+1].t;
        }
        v[N-1].t = NULL;
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
    TreeLinkNode * root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);
    root->right->left = new TreeLinkNode(6);
    root->right->right = new TreeLinkNode(7);

    s.connect(root);
    cout << root->left->left->next->next->val << endl;

    return 0;
}

