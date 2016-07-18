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
    int countNodes(TreeNode* root) {
        int cnt = 0;
        int h=0;
        
        if(root == NULL)
            return 0;
        
        int ll = getLeft(root);
        int lr = getRight(root);
        
        if(ll == lr) {
            cnt = (1 << ll) -1;
        }
        else {
            cnt = countNodes(root->left) + countNodes(root->right) + 1;
        }
        
        return cnt;
    }
    
    int getLeft(TreeNode * root) {
        int len = 0;
        
        while(root) {
            root = root->left;
            len++;
        }
        return len;
    }
    
    int getRight(TreeNode * root) {
        int len = 0;
        
        while(root) {
            root = root->right;
            len++;
        }
        return len;
    }
    
};

int main() {


    Solution s;
    return 0;
}

