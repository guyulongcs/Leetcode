class Solution {
public:
vector<int> singleNumber(vector<int>& nums) {
    int res[] = {0, 0};
    
    //a xor b
    int sum = 0;
    int len = nums.size();
    
    for (int i=0; i < len; i++) {
        sum = sum ^ nums[i];
    }
    cout << sum<< endl;
   
    //get a and b
    //get last 1
    int tmp = (sum & (-sum));
    for(int j=0; j < len; j++) {
        if((tmp & nums[j]) == 0) {
            res[0] ^= nums[j];
        }
        else
        {
            res[1] ^= nums[j];
        }
    }
    
    vector<int> ret(res, res+2);
    
   
    return ret;

}
};
