class Solution {
public:
    int titleToNumber(string s) {
    int res = 0;
     if(s.length() == 1)
     {
         res = s[0]-'A'+1;
     }
     else
     {
         string tmp =s.substr(0, s.length()-1);
         
         int tmpN = this->titleToNumber(s.substr(0, s.length()-1));
         res = tmpN * 26 + this -> titleToNumber(s.substr(s.length()-1));
     }
     return res;
    }
};
