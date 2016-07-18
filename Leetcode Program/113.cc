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
    vector< vector<int> > pathSum(TreeNode* root, int sum) {
        vector< vector<int> > vv;
        vector<int> v;
        
        dfs(root, sum, 0, v, vv);
        return vv;
    }
    
    
    void dfs(TreeNode* root, int sum, int s, vector<int> v,  vector< vector<int> >& vv) {
        if(root == NULL)
            return;
        
        v.push_back(root->val);
        s += root->val;
        
        if(root->left == NULL && root->right == NULL) {
            if(sum == s) {
                vv.push_back(v);
            }
        }
        
        dfs(root->left, sum, s, v, vv);
        dfs(root->right, sum, s, v, vv);
    }
    
    int getNum(vector<int> v) {
        int res = 0;
        for(int i=0; i < v.size(); i++) {
            res = res * 10 + v[i];
        }
        return res;
    }
    
    void printV(vector<int> v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    
    void printVV(vector< vector<int> > vv ) {
        for(int i=0; i < vv.size(); i++) {
            printV(vv[i]);
        }
    }

    
    
};


int main() {

    Solution s;
    TreeNode * root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);

    root->right = new TreeNode(8);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    vector< vector<int> > vv = s.pathSum(root, 22);
    s.printVV(vv);
    

    return 0;
}

