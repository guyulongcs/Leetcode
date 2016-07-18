#include<iostream>
#include<vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode * res = NULL;
        int N = nums.size();
        res = sortedArrayToBSTFunc(nums, 0, N-1);
        return res;
        
    }
    
    TreeNode* sortedArrayToBSTFunc(vector<int>& nums, int low, int high) {
        if(low > high)
            return NULL;
        
        int mid = (low+high)/2;
        
       
        TreeNode * T = new TreeNode(nums[mid]);
        T->left = sortedArrayToBSTFunc(nums, low, mid-1);
        T->right = sortedArrayToBSTFunc(nums, mid+1, high);
        return T;
    }
};

int main() {
    Solution s = Solution();
    int res = 0;
    int a[] = {3,4,5,6,7};
    vector<int> v (a, a + sizeof(a) / sizeof(int));
    TreeNode * T = s.sortedArrayToBST(v);
    res = T->val;
    
    
    cout << res << endl;
}

