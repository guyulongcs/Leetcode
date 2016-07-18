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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        dfs(root, res, vector<int>());
        return res;
    }
    
    void dfs(TreeNode* root, vector<string>& res, vector<int> v) {
        if(root == NULL)
            return;
        
        v.push_back(root->val);
        
        if(root->left == NULL && root->right == NULL) {
            string s = getStr(v);
            res.push_back(s);
        }
        
        dfs(root->left, res, v);
        dfs(root->right, res, v);

    }
    
    string getStr(vector<int> v) {
        string res = "";
        int N = v.size();
//        cout << "N:" << N << endl;
        if(N == 0)
            return res;
        
        for(int i=0; i < N-1; i++) {
            res += to_string(v[i]) + "->";
        }
        res += to_string(v[N-1]);
//        cout << "res: " << res << endl;
        
        
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

    vector<string> res = s.binaryTreePaths(root);
    
    for(int i=0; i < res.size(); i++) {
        cout << res[i] << "\t" << endl;
    }

    cout << endl;

    return 0;
}

