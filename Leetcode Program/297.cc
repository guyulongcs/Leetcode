#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <set>
#include <cstdlib>


using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct QueueNode {
    TreeNode * val;
    int h;
    QueueNode(TreeNode * v, int hn) : val(v), h(hn){}
};
class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        vector<string> v;
        bfs(root, v);
        if(v.size() == 0)
            return res;
//        else {
//            cout << v[0] << endl;
//        }
        removeEndNull(v);
        res = vecString2String(v);
        return res;
    }
    
    void removeEndNull(vector<string> & v) {
        while(v.size() > 1 && v[v.size()-1]== "null") {
            v.erase(v.end()-1);
        }
    }
    
    string vecString2String(vector<string> & v) {
        string res;
        int N=v.size();
        for(int i=0; i < N; i++) {
            string str = "";
            if(i > 0)
                str = ",";
            res = res + str + v[i];
        }
        return res;
    }
    
    vector<string> string2VecString(string s) {
        vector<string> v;
        if(s.size() == 0)
            return v;
        size_t start_pos = 0;
        while(true) {
            string str = "";
            size_t p = s.find(",", start_pos);
            if(p != string::npos) {
                str = s.substr(start_pos, p-start_pos);
                v.push_back(str);
                start_pos = p + 1;
            }
            else {
                str = s.substr(start_pos);
                v.push_back(str);
                break;
            }
        }
        return v;
    }
    
    
    
    int getTreeHeight(TreeNode * root) {
        if(root == NULL)
            return 0;
        int hl = getTreeHeight(root->left);
        int hr = getTreeHeight(root->right);
        int h = max(hl, hr)+1;
        return h;
        
    }
    
    void bfs(TreeNode * root, vector<string> & v) {
        if(root == NULL) {
            return;
        }
        int th = getTreeHeight(root);
        queue<QueueNode> q;
        q.push(QueueNode(root, 1));
        while(!q.empty()) {
            QueueNode node = q.front();
            q.pop();
            
            if(!(node.val)) {
                v.push_back("null");
                continue;
            }
            
            v.push_back(to_string((node.val)->val));
            if(node.val && node.h < th) {
                q.push(QueueNode(node.val->left, node.h+1));
                q.push(QueueNode(node.val->right, node.h+1));
            }
        }

        
        
    }
    
    
    void printVecString(vector<string> & v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    
    TreeNode* createTreeFromVecString(vector<string> & v) {
        TreeNode * T = NULL;
        int N=v.size();
        if(N==0)
            return T;
        queue<TreeNode *> q;
        
        int cnt=0;
        for(int i=0; i < N; i++) {
            //node
            TreeNode * node = NULL;
            int n=0;
            string str = v[i];
            if(v[i] != "null") {
                n = atoi(v[i].c_str());
                node = new TreeNode(n);
            }
           
            
            //root
            if(T == NULL) {
                T = node;
                q.push(T);
                continue;
            }
            
            cnt++;
            //par
            TreeNode * p = q.front();
            if(cnt == 1) {
                p->left = node;
            }
            else {
                p->right = node;
                q.pop();
                cnt=0;
            }
            if(node != NULL)
                q.push(node);
        }
        
        return T;
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode*  T = NULL;
        
        vector<string> v = string2VecString(data);
        printVecString(v);
        
        T = createTreeFromVecString(v);
        
        return T;
    }
};


int main() {


    Codec codec;
    string s = "1,2,3,null,null,4,5";
    TreeNode * T =codec.deserialize(s);
//    if(T != NULL) {
//        cout << "T != NULL" << endl;
//    }
    
    //cout << T->right->left->right->val << endl;
//    TreeNode * T = new TreeNode(1);
//    T->left = new TreeNode(2);
//    T->right = new TreeNode(3);
//    T->left->left = new TreeNode(4);
    //T->right->right = new TreeNode(5);
    
  
    string str = codec.serialize(T);
    cout << str << endl;
    
//    TreeNode * T2=codec.deserialize(str);
//
//    cout << T2->left->left->val << endl;
    return 0;
}

