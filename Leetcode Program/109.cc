#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int getLen(ListNode* head) {
        ListNode * p=head;
        int len=0;
        while( p != NULL) {
            len++;
            p = p->next;
        }
        return len;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) {
            return NULL;
        }
        
        TreeNode * T = NULL;
        T = createTree(head);
        return T;
    }
    
    TreeNode * createTree(ListNode* head) {
        ListNode * slow = head;
        ListNode * fast = head;
        
        TreeNode * T = NULL;
        if(head == NULL)
            return NULL;
        
        if(head->next == NULL) {
            T = new TreeNode(head->val);
            return T;
        }
        ListNode * pre= NULL;
        while(fast && fast->next) {
            pre=slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        TreeNode * root = new TreeNode(slow->val);
        if(!pre)
            return root;
        pre->next = NULL;
        root->left = createTree(head);
        root->right = createTree(slow->next);
        
        return root;
    }
};

int main() {

    ListNode * pl = new ListNode(1);
    pl->next = new ListNode(2);
    pl->next->next = new ListNode(3);
    
    

    Solution s;
    TreeNode* p = s.sortedListToBST(pl);
    cout << p->val << endl;
    cout << p->left->val << endl;
    cout << p->right->val << endl;



    return 0;
}

