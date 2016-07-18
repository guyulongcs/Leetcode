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

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
        vector<int> vv;
        vector<int> v;
        dfs(root, vv, v);
        
        int res = 0;
        for(int i=0; i < vv.size(); i++) {
//            cout << "vv[i]: " << vv[i] << endl;
            res += vv[i];
        }
        return res;
    }
    
    void dfs(TreeNode* root, vector<int> & vv, vector<int> v) {
        if(root == NULL)
            return;
        v.push_back(root->val);
        if(root->left == NULL && root->right == NULL) {
            int num = getNum(v);
            vv.push_back(num);
            return;
        }
        dfs(root->left, vv, v);
        dfs(root->right, vv, v);
    }
    
    int getNum(vector<int> v) {
        int res = 0;
        for(int i=0; i < v.size(); i++) {
            res = res * 10 + v[i];
        }
        return res;
    }
};


int main() {

    Solution s;
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
//    root->right->left = new TreeNode(15);
//    root->right->right = new TreeNode(7);

    int res = s.sumNumbers(root);

    cout << res << endl;

    return 0;
}

