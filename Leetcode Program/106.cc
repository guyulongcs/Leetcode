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

class Tree {
public:
    static void printTree(TreeNode * T) {
        
        printTree_dfs(T, "");
       
    }
    
    static void printTree_dfs(TreeNode * T, string s) {
        if(T==NULL)
            return;
        cout << s << T->val << endl;
        s = s +"\t";
        printTree_dfs(T->left, s);
        printTree_dfs(T->right, s);
        
    }
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode * T = NULL;
        int N = inorder.size();
        
        T = buildTreeRange(inorder, postorder, 0, N-1, 0, N-1);
        return T;
    }
    
    TreeNode * buildTreeRange(vector<int>& inorder, vector<int>& postorder, int ib, int ie, int pb, int pe) {
//        cout  << endl << "buildTreeRange" << endl;
//        printVector(inorder, ib, ie);
//        printVector(postorder, pb, pe);
        
        TreeNode * T = NULL;
        int N = ie - ib;
        if(N < 0)
            return T;
        int r = postorder[pe];
        int ir = findInorderValue(inorder, ib, ie, r);
        T = new TreeNode(r);
        T->left = buildTreeRange(inorder, postorder, ib, ir-1, pb, pb+ir-1-ib);
        T->right = buildTreeRange(inorder, postorder, ir+1, ie, pb+ir-ib, pe-1);
        return T;
    }
    
    int findInorderValue(vector<int>& inorder, int ib, int ie, int r) {
        int res = ib;
        for(int i=ib; i <= ie; i++) {
            if(inorder[i] == r) {
                res = i;
                break;
            }
        }
        return res;
    }
    
    void printVector(vector<int>& v, int b, int e) {
        for(int i=b; i <= e; i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    
};

int main() {

    Solution s;
    vector<int> vi({4,2,5,1,3});
    vector<int> vp({4,5,2,3,1});
    
    TreeNode * T = s.buildTree(vi, vp);
    Tree::printTree(T);
    
//    cout <<T->val << endl;
    

    return 0;
}

