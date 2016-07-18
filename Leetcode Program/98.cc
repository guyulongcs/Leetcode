#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;



//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };
//

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        int tmin = 0;
        int tmax = 0;
        
        bool flag = dfs(root, tmin, tmax);
        return flag;
    }
    
    bool dfs(TreeNode* root, int & tmin, int & tmax) {
        
        
        if(root == NULL) {
            return true;
            tmin = 0;
            tmax=0;
        }
        
        int lmin, lmax;
        int rmin, rmax;
        
        bool flag = true;
        
        tmin = root->val;
        tmax = root->val;
        
        if(root->left != NULL) {
            flag = dfs(root->left, lmin, lmax);
            tmin = lmin;
            if(!flag || (lmax >= root->val))
                return false;
            
        }
        if(root->right != NULL) {
            flag = dfs(root->right, rmin, rmax);
            tmax = rmax;
            if(!flag || (rmin <= root->val))
                return false;
        }
        return true;
    }
};


int main() {

    Solution s;
    TreeNode * root=new TreeNode(3);
    root->left = new TreeNode(1);
//    root->right = new TreeNode(4);


    bool res = s.isValidBST(root);
    cout << res << endl;

    return 0;
}

