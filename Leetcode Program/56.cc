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

bool Cmp(const Interval & i1, const Interval & i2) {
    bool flag = false;
    if(i1.start < i2.start || (i1.start == i2.start && i1.end < i2.end)) {
        flag = true;
    }
    return flag;
}

class IntervalTool {
public:
    static vector<Interval> mergeIntervals(vector<Interval>& intervals) {
        vector<Interval> res;
        
        
        int N = (int)intervals.size();
        if(N <= 1)
            return intervals;
        
        int s=0;
        int e=0;
        for(int i=0; i < N; i++) {
            Interval interval = intervals[i];
            if(i==0) {
                s = interval.start;
                e = interval.end;
            }
            else {
                if(interval.start > e+1) {
                    res.push_back(Interval(s, e));
                    s = interval.start;
                    e = interval.end;
                }
                else {
                    e = interval.end;
                }
            }
        }
        res.push_back(Interval(s, e));
        
        return res;
    }
    
    static void printVInterval(vector<Interval> & intervals) {
        for(int i=0; i < intervals.size(); i++) {
            cout << intervals[i].start << "\t" << intervals[i].end << endl;
        }
    }
    
    static void printInterval(Interval inte) {
        cout << inte.start << "\t" << inte.end << endl;
    }
};
class Solution {
public:
    
    void getVecMinMax(vector<Interval>& intervals, int & nmin, int & nmax) {
        nmin = INT32_MAX;
        nmax = INT32_MIN;
        
        for(int i=0; i < intervals.size(); i++) {
            nmin = min(nmin, intervals[i].start);
            nmax = max(nmax, intervals[i].end);
        }
    }
    
    bool mergeTwoInterval(Interval & i1, Interval & i2, Interval & merge) {
        bool flag = false;
        if(i1.end >= i2.start) {
            flag = true;
            merge = Interval(i1.start, max(i1.end, i2.end));
        }
        
//        cout << endl << "i1:" << endl;
//        IntervalTool::printInterval(i1);
//        
//        cout << endl << "i2:" << endl;
//        IntervalTool::printInterval(i2);
//        
//        cout << endl << "flag:" << flag << endl;
//        
//        cout << endl << "merge:" << endl;
//        IntervalTool::printInterval(merge);
//        
        return flag;
    }
    void mergeIntervalVecVec(vector<Interval> & left, vector<Interval> & right, vector<Interval> & merge) {
       
        int sl = left.size();
        int sr = right.size();
        if(sl == 0)
            merge = right;
        else if(sr == 0)
            merge = right;
        else {
            for(int i=0; i < sl-1; i++) {
                merge.push_back(left[i]);
            }
            
            Interval le = left[sl-1];
            
            Interval mergeCur;
            
            
            bool flag = true;
            
            
            int i=0;
            for(i=0; i < sr; i++) {
                flag = mergeTwoInterval(le, right[i], mergeCur);
                if(flag) {
                    //merge.push_back(mergeCur);
                    le = mergeCur;
                }
                else {
//                    merge.push_back(le);
//                    merge.push_back(right[i]);
                    break;
                }
            }
            
            merge.push_back(le);
            //i++;
            for(; i < sr; i++) {
                merge.push_back(right[i]);
            }
        }
        
//        cout << endl << "left:" << endl;
//        IntervalTool::printVInterval(left);
//        
//        cout << endl << "right:" << endl;
//        IntervalTool::printVInterval(right);
//        
//        cout << endl << "merge:" << endl;
//        IntervalTool::printVInterval(merge);
    }
    
    vector<Interval> mergeIntervals2(vector<Interval>& intervals, int s, int e) {
//        cout << "s,e:" << s << "\t" << e << endl;
        if(s == e) {
            vector<Interval> v;
            v.push_back(intervals[s]);
            return v;
        }
        
        int m = (s+e)/2;
        vector<Interval> left = mergeIntervals(intervals, s, m);
        vector<Interval> right = mergeIntervals(intervals, m+1, e);
        vector<Interval> merge;
        mergeIntervalVecVec(left, right, merge);
        return merge;
    }
    
    vector<Interval> mergeIntervals(vector<Interval>& intervals, int s, int e) {
        vector<Interval> res;
        Interval cur  = intervals[s];
        Interval mergeCur;
        for(int i = s+1; i <= e; i++) {
            bool flag = mergeTwoInterval(cur, intervals[i], mergeCur);
            if(flag) {
                cur = mergeCur;
            }
            else {
                res.push_back(cur);
                cur = intervals[i];
            }
        }
        res.push_back(cur);
        return res;
    }
    
    
    
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        
        if(intervals.size() == 0) {
            return res;
        }
        
        int nmin;
        int nmax;
        
        sort(intervals.begin(), intervals.end(), Cmp);
        
        res = mergeIntervals(intervals, 0, intervals.size()-1);
        
        
        return res;
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
////    Interval newInterval = Interval(4, 9);
//
//    vector<Interval> intervals;
//    intervals.push_back(Interval(0,1));
//     intervals.push_back(Interval(5,5));
//    intervals.push_back(Interval(6,7));
//    intervals.push_back(Interval(9,11));
//    Interval newInterval = Interval(12,21);
//
//
//    vector<Interval> res = s.insert(intervals, newInterval);



    vector<Interval> intervals;
    intervals.push_back(Interval(2,3));
    intervals.push_back(Interval(4,5));
    intervals.push_back(Interval(6,7));
    intervals.push_back(Interval(8,9));
    intervals.push_back(Interval(1,10));

    vector<Interval> res;

    res = s.merge(intervals);

    for(int i=0; i < res.size(); i++) {
        Interval interval = res[i];
        cout << interval.start << "\t" << interval.end << endl;
    }

    
    
    
    return 0;
}
