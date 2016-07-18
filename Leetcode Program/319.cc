#include <iostream>
#include <string> 
#include <vector>
using namespace std;

int factorCnt(int n) {
    int cnt=0;
    for (int i=1; i<=n; i++) {
        if(n%i == 0)
            cnt++;
    }
    return cnt;
}
int bulbSwitch(int n) {
    int sum = 0;
    for (int i=1; i <= n; i++) {
        if(factorCnt(i) % 2 != 0)
            sum+=1;
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    for(int i=1; i<=10;i++)
        cout << bulbSwitch(i) << endl;
    
    int n = 99999;
    cout << bulbSwitch(n) << endl;
    
    return 0;
}

