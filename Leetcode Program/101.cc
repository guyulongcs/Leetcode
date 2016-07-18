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
    int pos;
    QueueNode(TreeNode * tn=NULL, int l=0, int p=0) : t(tn), level(l), pos(p) {}
};

class Tree {
    TreeNode * T;
    Tree() {
        T = NULL;
    }
    void createTree(vector<string> v) {
        
    }
};


class Vector {
public:
    static void printVector(vector<QueueNode> v) {
        cout << "vec:";
        for(int i=0; i < v.size(); i++) {
            cout << (v[i].t)->val << "\t";
        }
        cout << endl;
        
    }
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isSymmetricTrees(root->left, root->right);

    }
    
    bool isSymmetricTrees(TreeNode * t1, TreeNode * t2) {
        bool flag = true;
        if(t1 == NULL && t2 == NULL)
            return true;
        else if(t1 == NULL || t2 == NULL) {
            return false;
        }
        if(t1->val != t2->val)
            return false;
        
        flag = isSymmetricTrees(t1->left, t2->right) && isSymmetricTrees(t1->right, t2->left);
        return flag;
    }
    

    bool isSymmetricBFS(TreeNode* root) {
        if(root == NULL)
            return true;
        
        if(root->left == NULL && root->right == NULL) {
            return true;
        }
        
        int level = 1;
        queue<QueueNode> q;
        q.push(QueueNode(root, level, 1));
        
        vector<QueueNode> v;
        
        bool flag = true;
        
        int treeHeight = getTreeHeight(root);
//        cout << "treeHeight:" << treeHeight << endl;
        while(!q.empty()) {
           
            
            QueueNode node = q.front();
            int nlevel = node.level;
            
            TreeNode * T = node.t;
            
            
            if(nlevel != level) {
//                cout <<"nlevel:" << nlevel << endl;
                if(!isSymmetricVector(v)) {
                    flag = false;
                    break;
                }
//                cout <<"flag:" << flag << endl;
                v.clear();
                level = nlevel;
            }
            
            if(T == NULL) {
//                v.push_back(INT32_MIN);
//                if(nlevel < treeHeight) {
//                    q.push(QueueNode(NULL, nlevel + 1));
//                    q.push(QueueNode(NULL, nlevel + 1));
//                }
                
            }
            else {
                v.push_back(node);
                
        //            if(T->left == NULL && T->right == NULL)
        //                continue;
                
                if(nlevel < treeHeight) {
                    if(T->left != NULL)
                        q.push(QueueNode(T->left, nlevel + 1, (node.pos) *2));
                    if(T->right != NULL)
                        q.push(QueueNode(T->right, nlevel + 1, (node.pos) *2+1));
                }
            }
            
            q.pop();

        }
        if(!flag || !isSymmetricVector(v)) {
            flag = false;
        }
        return flag;
    }
    
    int getTreeHeight(TreeNode* root) {
        if(root == NULL)
            return 0;
        int res = 1 + max(getTreeHeight(root->left), getTreeHeight(root->right));
        return res;
    }
                   
   bool isSymmetricVector(vector<QueueNode> v) {
//       Vector::printVector(v);
       if(v.size() == 0)
           return true;
       
       int level = v[0].level;
       if(level == 1)
           return true;
       else if(v.size() %2 > 0)
           return false;

       
       bool flag = true;
       int i=0;
       int N = v.size();
       int j=N-1;
       while(i < j) {
           if(!isSymmetricNode(v[i], v[j])) {
               flag = false;
               break;
           }
           i++;
           j--;
       }
       return flag;
   }
    
    bool isSymmetricNode(QueueNode n1, QueueNode n2) {
        bool flag = true;
        int level = n1.level;
        if((n1.t)->val != (n2.t)->val) {
            flag = false;
        }
        else {
            int left = 1 <<(level-1) ;
            int right = (1 <<level)-1;
            if((n1.pos - left) != (right -n2.pos)) {
                flag = false;
            }
        }
        return flag;
    }
};



int main() {
    
    Solution s;
//    TreeNode * root = new TreeNode(3);
//    root->left = new TreeNode(2);
//    root->right = new TreeNode(2);
//    root->left->right = new TreeNode(4);
//    root->right->left = new TreeNode(4);

    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
//    root->right = new TreeNode(2);

    
    
    bool res = s.isSymmetric(root);
    
    cout << res << endl;
    
    return 0;
}

