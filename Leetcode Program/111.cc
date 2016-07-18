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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int level = 1;
        queue<QueueNode> q;
        q.push(QueueNode(root, level));
        
        vector<int> v;
        
        while(!q.empty()) {
            QueueNode node = q.front();
            int nlevel = node.level;
            
            TreeNode * T = node.t;
            
            if(T->left == NULL && T->right == NULL) {
                level = nlevel;
                break;
            }
            
            if(T->left != NULL) {
                q.push(QueueNode(T->left, nlevel + 1));
            }
            if(T->right != NULL) {
                q.push(QueueNode(T->right, nlevel + 1));
            }
            
            q.pop();

        }
        return level;
    }
};


int main() {
    
    Solution s;
    TreeNode * root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    int res = s.minDepth(root);
    
    cout << res << endl;
    
    return 0;
}

