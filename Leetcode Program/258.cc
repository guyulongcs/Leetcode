class Solution {
public:
    int addDigits(int num) {
        int res = 0;
        const int N = 9;
        if(num < 10) {
            res = num;
        }
        else if(num % N == 0) {
            res = N;
        }
        else {
            res = num - N * (num / N);
        }
        return res;
    }
};
