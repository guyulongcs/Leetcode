#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>



using namespace std;

class Solution {
public:
    
    string getHint(string secret, string guess) {
        int N = secret.length();
        
        vector<bool> flag(N+1, false);

        unordered_map<char, int> gmap;
        int tcnt = 0;
        int fcnt = 0;
        
        for(int i=0; i < N; i++) {
            char sch = secret[i];
            char gch = guess[i];
            if(sch == gch) {
                flag[i] = true;
                tcnt++;
            }
            else {
                if(gmap.find(gch) == gmap.end())
                    gmap[gch] = 0;
                gmap[gch]++;
            }
        }
        
        for(int i=0; i < N; i++) {
            char sch = secret[i];
            if(flag[i] == false) {
                if(gmap.find(sch) != gmap.end() ) {
                    if(gmap[sch] > 0) {
                        fcnt++;
                        gmap[sch]--;
                    }
                }
            }
        }
        
        string s1= std::to_string(tcnt) + 'A';
        string s2= std::to_string(fcnt) + 'B';
        string res = s1+s2;
        return res;

    }
    
};


int main() {
    

    Solution s;
    vector<int> v({1,2,3});
    
    string secret="1123";
    string guess = "0144";
    string res= s.getHint(secret, guess);
    cout << res << endl;
    
    
    return 0;
}

