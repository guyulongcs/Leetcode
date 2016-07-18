#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


struct Interval {
public:
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

struct Cmp {
    
    bool operator() (const Interval & i1, const Interval & i2) {
        return i1.start < i2.start;
    }
    
};

class SummaryRanges {
    set<Interval, Cmp> st;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        Interval interval(val, val);
        
        int start = val;
        int end = val;
        
        auto it = st.lower_bound(interval);
       
        if(it != st.begin()) {
            it--;
            if(it->end + 1 < val)
                it++;
        }
        
        while(true) {
            if(it == st.end() || it->start > val+1 || it->end < (val-1))
                break;
            start = min(start, it->start);
            end = max(end, it->end);
            it = st.erase(it);
        }
        
        st.insert(it, Interval(start, end));
    }
    
    
    vector<Interval> getIntervals() {
        vector<Interval> res;
        for(auto val:st)
            res.push_back(val);
        return res;
    }
    
    void printIntervals(vector<Interval> & v) {
        for(int i=0; i < v.size(); i++) {
            Interval interval= v[i];
            cout << "[" << interval.start << ", " << interval.end << "]" << "\t";
        }
        cout << endl;
    }
    
};

int main() {

    SummaryRanges obj = SummaryRanges();
    
    vector<int> v({1,3,7,2});
    for(int i=0; i < v.size(); i++) {
        obj.addNum(v[i]);

    }
    
    vector<Interval> res = obj.getIntervals();
   
    obj.printIntervals(res);
    
    return 0;
}

