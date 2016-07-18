class Solution {
public:
    int climbStairs(int n) {
        const double c = sqrt(5);
        double res = (1/c)*(pow(((1+c)/2),n+1) - pow(((1-c)/2), n+1));
        int iRes = (int)res;
        return iRes;
    }
}
