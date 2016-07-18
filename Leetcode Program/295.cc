#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;


class MedianFinder {
    priority_queue< int, vector<int>, less<int> > hg;
    priority_queue< int, vector<int>, greater<int> > hl;
    
public:
    
    // Adds a number into the data structure.
    void addNum(int num) {
        if(hg.size() == 0) {
            hg.push(num);
        }
        else if(num >= hg.top()) {
            hl.push(num);
            balance();
        }
        else {
            hg.push(num);
            balance();
        }
    }
    
    void balance() {
        if(hg.size() > hl.size() + 1) {
            int num = hg.top();
            hg.pop();
            hl.push(num);
        }
        else if(hg.size() < hl.size()) {
            int num = hl.top();
            hl.pop();
            hg.push(num);
        }
    }
    
    // Returns the median of current data stream
    double findMedian() {
        double res=0.0;
        if(hg.size() == hl.size()) {
            res = (double)(hg.top() + hl.top()) / 2;
        }
        else {
            res = hg.top();
        }
        return res;
    }
    
};


int main() {
     MedianFinder mf;
     mf.addNum(3);
     mf.addNum(4);
     mf.addNum(5);
     mf.addNum(2);
     mf.addNum(1);
     double res = mf.findMedian();
     cout << res << endl;
    
    return 0;
}

