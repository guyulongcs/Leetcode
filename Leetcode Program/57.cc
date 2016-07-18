#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;



struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class IntervalTool {
public:
    static void printVInterval(vector<Interval> & intervals) {
        for(int i=0; i < intervals.size(); i++) {
            cout << intervals[i].start << "\t" << intervals[i].end << endl;
        }
    }
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval>::iterator it;
        for(it = intervals.begin(); it != intervals.end();) {
            Interval interval = *it;
            if(newInterval.end < interval.start) {
                intervals.insert(it, newInterval);
                return intervals;
            }
            else if(newInterval.start > interval.end) {
                it++;
            }
            else {
                int start = min(interval.start, newInterval.start);
                int end = max(interval.end, newInterval.end);
                Interval intervalMerge(start, end);
                vector<Interval>::iterator itNext = it+1;
                intervals.erase(it);
                newInterval = intervalMerge;
            }
        }
        if(it == intervals.end()) {
            intervals.push_back(newInterval);
        }
        return intervals;
    }
    
    void getVecMinMax(vector<Interval>& intervals, int & nmin, int & nmax) {
        nmin = INT32_MAX;
        nmax = INT32_MIN;
        
        for(int i=0; i < intervals.size(); i++) {
            nmin = min(nmin, intervals[i].start);
            nmax = max(nmax, intervals[i].end);
        }
    }
};


int main() {


    Solution s;
//    vector<Interval> intervals;
//    intervals.push_back(Interval(1,2));
//    intervals.push_back(Interval(3,5));
//    intervals.push_back(Interval(6,7));
//    intervals.push_back(Interval(8,10));
//    intervals.push_back(Interval(12,16));
//
//    Interval newInterval = Interval(4, 9);

    vector<Interval> intervals;
    intervals.push_back(Interval(1,5));
    intervals.push_back(Interval(6,8));

   

    Interval newInterval = Interval(5,6);


    vector<Interval> res = s.insert(intervals, newInterval);
    for(int i=0; i < res.size(); i++) {
        Interval interval = res[i];
        cout << interval.start << "\t" << interval.end << endl;
    }

    return 0;
}
