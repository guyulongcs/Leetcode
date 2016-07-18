#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

unordered_map<int, int> mapValue;

class Solution {
public:
    int rob(TreeNode* root) {
        mapValue.clear();
        int res=robFunc(root, 1);
        return res;
    }
    
    int robFunc(TreeNode * root,  int n) {
        int res = 0;
        if(root == NULL)
            return 0;
        
        if(mapValue.find(n) != mapValue.end()) {
            return mapValue[n];
        }
        
        
        int v1 = getRobHasCurNode(root, n);
        int v2 = getRobNotHasCurNode(root,  n);
        
        int maxV = getMax(v1, v2);
        mapValue[n] = maxV;
        
        return maxV;
    }
    
    int getRobHasCurNode(TreeNode * root, int n) {
        
        int v1 = 0;
        
        int c1 = 0;
        int c2 = 0;
        int c3 = 0;
        int c4 = 0;
        
        if(root->left != NULL){
            c1 =robFunc(root->left->left,  n*2*2);
            c2 =robFunc(root->left->right,  (n*2)*2+1);
        }
        if(root->right != NULL) {
            c3 =robFunc(root->right->left, (n*2+1)*2);
            c4 =robFunc(root->right->right, (n*2+1)*2 + 1);
        }
        
        v1 = root->val + c1 + c2 + c3 + c4;
        return v1;
    }
    
    int getRobNotHasCurNode(TreeNode * root,  int n) {
        int d1 = robFunc(root->left,  n*2);
        int d2 = robFunc(root->right, n*2+1);
        int v2 = d1 + d2;
        return v2;
    }
    
    int getMax(int v1, int v2) {
        int res = (v1 > v2) ? v1 : v2;
        return res;
    }
};

int main() {
    Solution s = Solution();

    TreeNode * T = new TreeNode(3);
    T->left = new TreeNode(4);
    T->right = new TreeNode(5);
    T->left->left = new TreeNode(1);
    T->left->right = new TreeNode(3);
    T->right->right = new TreeNode(1);
    
    int res = s.rob(T);
    cout << res << endl;
}

