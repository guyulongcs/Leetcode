#include <iostream>
//#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <cstdlib>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int numTrees(int n) {
        int res = catlan(n);
        return res;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if(n==0)
            return res;
        vector< vector< vector<TreeNode*> > > a(n+1, vector < vector<TreeNode*> > (n+1, vector<TreeNode*>()));
        
        char buf[100];
        for(int k=1; k <= n; k++) {
            for(int i=n-k+1; i >= 1; i--) {
                for(int j=i+k-1; j <= i+k-1; j++) {
                    for(int m=i; m <= j; m++) {
                        
//                        sprintf(buf, "i:%d, j:%d, m:%d", i, j, m);
//                        cout <<"********************************"<<endl;
//                        cout << buf << endl;
                        
                        int value = m;
                        
                        vector<TreeNode*> leftTrees;
                        vector<TreeNode*> rightTrees;
                        vector<TreeNode*> trees;
                        
                        if(m-1 >= i)
                            leftTrees = a[i][m-1];
                        if(m+1 <= j)
                            rightTrees = a[m+1][j];
                        
                        int lc = leftTrees.size();
                        int rc = rightTrees.size();
                        
                        if(lc == 0 && rc == 0) {
                            TreeNode * T = new TreeNode(value);
                            trees.push_back(T);
                        }
                        else if(lc > 0 && rc > 0){
                            for(int ii=0; ii < leftTrees.size(); ii++) {
                                for(int jj=0; jj < rightTrees.size(); jj++) {
                                    TreeNode * T = new TreeNode(value);
                                    T->left = leftTrees[ii];
                                    T->right = rightTrees[jj];
                                    trees.push_back(T);
                                }
                            }
                        }
                        else {
                            if(lc > 0) {
                                for(int ii=0; ii < leftTrees.size(); ii++) {
                                    TreeNode * T = new TreeNode(value);
                                    T->left = leftTrees[ii];
                                    trees.push_back(T);
                                }
                            }
                            else {
                                for(int ii=0; ii < rightTrees.size(); ii++) {
                                    TreeNode * T = new TreeNode(value);
                                    T->right = rightTrees[ii];
                                    trees.push_back(T);
                                }
                            }
                        }
                        
//                        cout << "left, right:" << leftTrees.size() << ", " << rightTrees.size() << endl;
//                        cout << "trees:" << trees.size() << endl;
//                        printTrees(trees);

                        for(int ii=0; ii < trees.size(); ii++) {
                            a[i][j].push_back(trees[ii]);
                        }
                        

                    }
//                    cout << endl << "a[i][j]:" << a[i][j].size() << endl;
//                    printTrees(a[i][j]);
//                    cout << endl;
                    
                }
            }
        }
        
        return a[1][n];
    }
    
    void printTrees(vector<TreeNode*> & trees) {
        for(int i=0; i < trees.size(); i++) {
            printTree(trees[i]);
        }
    }
   
    void printTree(TreeNode * T) {
        //cout << endl << "Tree" << endl;
        
        string str = tree2Str(T);
        cout << str << endl;
        
    }
    
    string tree2Str(TreeNode * T) {
        //cout << "tree2Str" << endl;
        string str="";
        if(T==NULL)
            str = "#";
        queue<TreeNode *> q;
        q.push(T);
        char buf[100];
        while(!q.empty()) {
            TreeNode * node = q.front();
            string s = "#";
            if(node != NULL) {
                sprintf(buf, "%d", node->val);
                s = string(buf);
            }
            if(str != "")
                str += ",";
            str += s;
            q.pop();
            
            if(node == NULL)
                continue;
            if(node ->left != NULL || node->right != NULL) {
                //q.push(node->left);
                //q.push(node->right);
                
                if(node->left != NULL)
                    q.push(node->left);
                else
                    q.push(NULL);
                
                if(node->right != NULL)
                    q.push(node->right);
                else
                    q.push(NULL);
            }
            
        }
        
        return str;
    }
    
    int catlan(int n) {
        int * a = new int[n+1];
        a[0]=1;
        for(int i=1; i <= n;i++) {
            int sum=0;
            for(int k=1; k <=i; k++) {
                sum += a[k-1]*a[i-k];
            }
            a[i]=sum;
        }
        int res = a[n];
        delete []a;
        return res;
    }
};

int main() {
    
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> v(a, a+sizeof(a)/sizeof(int));

    Solution s;


    int m=3;
    int n=3;
    int aa[][3] = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    
    vector< vector<int> > vv;
    for(int i=0; i < m; i++) {
        vector<int> tmp;
        for(int j=0; j < n; j++) {
            tmp.push_back(aa[i][j]);
        }
        vv.push_back(tmp);
    }
    
    //int res = 0;
    vector<TreeNode*> res = s.generateTrees(4);
    cout << "Tree Cnt:" << res.size() << endl;
    s.printTrees(res);
    return 0;
}
