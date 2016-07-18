class Solution {
public:
    void getAlphaCountArray(string s, int * a) {
        
        for(int i=0; i < s.length(); i++) {
            int num = s[i]-'a';
            a[num] ++;
        }
    }
    
    bool isAnagram(string s, string t) {
        int sArr[100];
        int tArr[100];
        
        for(int i = 0; i < 100; i++) {
            sArr[i] = 0;
            tArr[i] = 0;
        }
        this -> getAlphaCountArray(s, sArr);
        this -> getAlphaCountArray(t, tArr);
        
        bool flag = true;
        for(int i=0; i < 26; i++) {
            if(sArr[i] != tArr[i]) {
                flag = false;
                break;
            }
        }
        return flag;
    }
};
