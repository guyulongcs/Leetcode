class Solution {
public:
    string convertToTitle(int n) {
    string res="";
    
    while(n > 0) {
        int num = (n-1) % 26;
        char ch = num + 'A';
        string s = "";
        s.push_back(ch);
        res = s + res;
        n = (n-1)/26;
    }
    return res;
    }
};
