// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long b=1;
        long long e=n;
        while(true) {
            long long m = (b+e)/2;
            if(isBadVersion(m)) {
                e = m;
            }
            else {
                b = m + 1;
            }
            if(b >= e)
                break;
        }
        int res=0;
        if(b == e) 
            res = e;
        else 
            res = 0;
        return res;
    }
};


