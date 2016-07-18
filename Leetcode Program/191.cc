class Solution {
public:
    int hammingWeight(uint32_t n) {
        int oneBitCount = 0;
        while( n > 0) {
            n = n & (n-1);
            oneBitCount++;
        }
        return oneBitCount;
    }
};
