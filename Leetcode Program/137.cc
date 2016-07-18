class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        vector<int> vc(32, 0);
        for(int i=0; i < (int)nums.size(); i++) {
            int tmp = nums[i];
            for(int j=0; j<32;j++){
                if((tmp & 1) > 0) {
                    vc[j]++;
                }
                tmp = (tmp >> 1);
            }
        }
        
        for(int i=0; i < 32; i++) {
            if(vc[i] > 0 && (vc[i] % 3!=0)) {
                res += (1<<i);
            }
        }
        return res;
    }
};
