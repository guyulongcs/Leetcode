#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct Person {
    int pos;
    int rate;
    Person(){}
    Person(int p=0, int r=0):pos(p), rate(r){}
    
    friend bool operator < (const Person & per1, const Person & per2) {
        bool flag = false;
        if(per1.rate < per2.rate) {
            flag = true;
        }
        else if(per1.rate > per2.rate) {
            flag = false;
        }
        else {
            if(per1.pos < per2.pos)
                flag = true;
        }
        return flag;
    }
    
    friend bool operator > (const Person & per1, const Person & per2) {
        return per2 < per1;
    }
    
};
class Solution {

public:
    
    int candy(vector<int>& ratings) {
        int res=0;
        
        int N = ratings.size();
        
        priority_queue<Person, vector<Person>, greater<Person>> pq;
        addPQ(ratings, pq);
        
        vector<int> vc(N, 0);
        
        greedy(ratings, N, pq, vc, res);
        
        return res;
    }
    
    void addPQ(vector<int>& ratings, priority_queue<Person, vector<Person>, greater<Person>> & pq) {
        for(int i=0; i < ratings.size(); i++) {
            Person per(i, ratings[i]);
            pq.push(per);
        }
    }
    
    bool isValidPos(int pos, int N) {
        return (pos >= 0 && pos <= N-1);
    }
    
    void greedy(vector<int>& ratings, int N, priority_queue<Person, vector<Person>, greater<Person>> & pq, vector<int> & vc, int & toalCnt) {
        
        while(!pq.empty()) {
            Person per = pq.top();
            pq.pop();
            int pos = per.pos;
            int cnt=1;
            if(isValidPos(pos-1, N)) {
                if(ratings[pos] > ratings[pos-1]) {
                    cnt = max(cnt, vc[pos-1]+1);
                }
            }
            if(isValidPos(pos+1, N)) {
                if(ratings[pos] > ratings[pos+1]) {
                    cnt = max(cnt, vc[pos+1]+1);
                }
            }
            vc[pos] = cnt;
            //cout << "pos, cnt:" << pos << "\t" << cnt << endl;
            toalCnt += cnt;
        }
    }
    
    void printVecStr(vector<string> & v) {
        for(int i=0; i < v.size(); i++) {
            cout << v[i] << "\t";
        }
        cout << endl;
    }
    
    void testPQ() {
        priority_queue<Person, vector<Person>, greater<Person>> pq;
        pq.push(Person(1,2));
        pq.push(Person(2,1));
       
        while(!pq.empty()) {
            Person per = pq.top();
            //cout << per.pos << "\t" << per.rate << endl;
            pq.pop();
        }
    }
};



int main() {
    Solution s= Solution();
    
    //s.testPQ();
    //return 0;
    
    vector<int> v({2,1});
   
    int res = s.candy(v);
    cout << res << endl;
   
    
    return 0;
}


