#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;


class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int cnt=0;
        int N = (int)words.size();
        vector<string> wline;
        string line;
        for(int i=0; i < N; i++) {
            string word = words[i];
            int wl = (int)word.length();
            if(wline.size() == 0) {
                cnt = wl;
            }
            else {
                cnt += 1+wl;
            }
            if(cnt > maxWidth) {
                line = getLineStr(wline, maxWidth, false);
                res.push_back(line);
                wline.clear();
                wline.push_back(word);
                cnt = wl;
            }
            else {
                wline.push_back(word);
            }
            
        }
        line = getLineStr(wline, maxWidth, true);
        res.push_back(line);
        
        
        return res;
    }
    
    string getLineStr(vector<string> & wline, int maxWidth, bool flagLast=false) {
        string res;
        int sl = sumLen(wline);
        int N = wline.size();
        if(flagLast == false && N > 1) {
            int padCnt = maxWidth - sl;
            int padAvg = padCnt / (N-1);
            int padMod = padCnt % (N-1);
            for(int i=0; i < N; i++) {
                if(i==0) {
                    res = wline[i];
                }
                else {
                    string padStr = getPadStr(padAvg, padMod, i);
                    res += padStr + wline[i];
                }
            }
        }
        else {
            string lastStr = getLastStr(wline, maxWidth);
            res = lastStr;
        }
        return res;
    }
    
    string getPadStr(int padAvg, int & padMod, int i) {
        string res;
        int padCnt = padAvg;
        if(padMod > 0) {
            padCnt += 1;
            padMod--;
        }
        for(int i=0; i < padCnt; i++) {
            res += " ";
        }
        return res;
    }
    
    string getLastStr(vector<string> & wline, int maxWidth) {
        string res;
        for(int i=0; i < wline.size(); i++) {
            if(i == 0) {
                res = wline[i];
            }
            else {
                res += " " + wline[i];
            }
        }
        int rlen = res.length();
        int padCnt = maxWidth-rlen;
        for(int i=0; i < padCnt; i++) {
            res += " ";
        }

        return res;
    }
    
    int sumLen(vector<string> & wline) {
        int res=0;
        for(int i=0; i < wline.size(); i++) {
            res += wline[i].length();
        }
        return res;
    }
    
    void printVS(vector<string> & v) {
        for(int i=0; i < v.size();i++) {
            cout << v[i] << endl;
        }
    }
};

int main() {
    Solution sol;
    
    vector<string> v;
    int maxWidth;
     vector<string> res;
    
    v = vector<string>({"Don't","go","around","saying","the","world","owes","you","a","living;","the","world","owes","you","nothing;","it","was","here","first."});
    maxWidth=30;
    
    
    res = sol.fullJustify(v, maxWidth);
    sol.printVS(res);
    
    return 0;
}

