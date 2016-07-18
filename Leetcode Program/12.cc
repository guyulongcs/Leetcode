#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int baseList[7] = {1000, 500, 100, 50, 10, 5, 1};
    int charList[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    
    int romanToInt(string s) {
        
        int res = 0;
        
        int N = s.length();
        for(int i=0; i < N; i++) {
            bool flag = false;
            
            int cur = romanCharToInt(s[i]);
            int tmp = cur;
            if(i < N-1){
                int next = romanCharToInt(s[i+1]);
                if(cur < next) {
                    tmp = 0 - cur;
                    
                }
            }
            res += tmp;
        }
        
        return res;
    }
    
    string intToRoman(int num) {
        string res = "";

        int N = sizeof(baseList) / sizeof(int);
        
        int base = 0;
        while(num > 0) {
            int baseValue =baseList[base];
            int baseCnt = num / baseValue;
            char curCh =intToRomanChar(baseValue);
        
//            cout << "\nbase: "<< base << endl;
//            cout << "baseCnt: "<< baseCnt << endl;
//            cout << "curCh: "<< curCh << endl;
        
            if(baseCnt > 0) {
                if(baseCnt < 4) {
                    for(int j=0; j<baseCnt;j++) {
                    res += curCh;
                    }
                    
                }
                else {
                    int len = res.length();
                    bool flag = true;
                    char preCh;
                    int preIndex;
                    int curIndex = base;
                    char nextCh;
                    
                    if(len > 0) {
                        preCh = res[len-1];
                        preIndex = getCharBaseIndex(preCh);
                       
           
                        if(curIndex - preIndex == 1) {
                            nextCh = charList[preIndex-1];
                            flag = false;
                            res[len-1] = curCh;
                            res += nextCh;
                        }
                    }
                    if(flag){
                        nextCh = charList[curIndex-1];
                        res = res + curCh + nextCh;
                    }
                }
                num = num % baseValue;
            }
            base ++;
            
        }
        
    
        return res;
    }
    
    int getValueBaseIndex(int n) {
        
        int index = -1;
        int N = sizeof(baseList) / sizeof(int);
        for(int i=0; i < N; i++) {
            if(baseList[i] == N)
                index = i;
        }
        return index;
    }
    
    int getCharBaseIndex(char ch) {
        
        int index = -1;
        int N = sizeof(charList) / sizeof(int);
        for(int i=0; i < N; i++) {
            if(charList[i] == ch)
                index = i;
        }
        return index;
    }

    

    
    int romanCharToInt(char ch) {
        int res = 0;
        int a[1001];
        memset(a, 0, sizeof(a));
        a['I'] = 1;
        a['V'] = 5;
        a['X'] = 10;
        a['L'] = 50;
        a['C'] = 100;
        a['D'] = 500;
        a['M'] = 1000;
        return a[ch];
    }
    
    char intToRomanChar(int n) {
        char ch ;
        int a[1001];
        memset(a, 0, sizeof(a));
        
        a[1000] = 'M';
        a[500] = 'D';
        a[100] = 'C';
        a[50] = 'L';
        a[10] = 'X';
        a[5] = 'V';
        a[1] = 'I';
        return a[n];
    }
    
};

int main() {
    Solution s = Solution();
    string str="DCXXI";
    int n = s.romanToInt(str);
    cout << str << ":" << n << endl;
    
    n = 1997;
    str = s.intToRoman(n);
    cout << n << ":" << str << endl;

}

