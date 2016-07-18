#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return head;
        ListNode * res = head;
        int prev = head->val;
        ListNode * prevNode = head;
        for(ListNode * curNode = head->next; curNode != NULL; ) {
            if(curNode->val == prev) {
                prevNode->next = curNode->next;
                ListNode * tmp = curNode;
                curNode=curNode->next;
                delete tmp;
            }
            else {
                prevNode = curNode;
                prev = curNode->val;
                curNode = curNode->next;
                
            }
            
        }
        return res;
    }
};

int main() {
    Solution s = Solution();

    ListNode * T = new ListNode(1);
    T->next = new ListNode(2);
    T->next->next = new ListNode(2);
    
    T = s.deleteDuplicates(T);
    cout << T->val << " " << T->next->val << endl;
    
    int res = 0;
    
    cout << res << endl;
}

