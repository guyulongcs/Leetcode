#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

struct CPoint {
    int x;
    int y;
    CPoint() : x(0), y(0) {}
    CPoint(int a, int b) : x(a), y(b) {}
    friend bool operator == (const CPoint & p1, const CPoint & p2) {
        return  (p1.x == p2.x && p1.y == p2.y);
    }
    
    void printInfo() {
        cout << x << "," << y << endl;
    }
    
    static double calK(const CPoint & p1, const CPoint & p2) {
        double k=0.;
        int deltax = p2.x - p1.x;
        int deltay = p2.y - p1.y;
        if(deltax == 0) {
            k = INT32_MAX;
        }
        else {
            k = (double)deltay / (double)deltax;
        }
        return k;
    }
    
    static vector<CPoint> Points2CPoints(vector<Point>& points) {
        vector<CPoint> v;
        for(int i=0; i < points.size(); i++) {
            v.push_back(CPoint(points[i].x, points[i].y));
        }
        return v;
    }
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int res=0;
        vector<CPoint> cpoints = CPoint::Points2CPoints(points);
        res = maxCPoints(cpoints);
        return res;

    }
    int maxCPoints(vector<CPoint>& cpoints) {
        int res=0;
        int N = (int)cpoints.size();
        
        
        
        for(int i=0; i < N; i++) {
            int curMax = 1;
            unordered_map<double, int> mapKCnt;
            int sameCnt=0;
            
            CPoint p1 = cpoints[i];
            //            p1.printInfo();
            for(int j=0; j < N; j++) {
                if(j == i) {
                    continue;
                }
                
                CPoint p2 = cpoints[j];
                
                //                cout << "p2:" << endl;
                //                p2.printInfo();
                if(p1 == p2) {
                    sameCnt++;
                    curMax = max(curMax, sameCnt+1);
                }
                else {
                    double k = CPoint::calK(p1, p2);
                    //                    cout << "k:" << k << endl;
                    if(mapKCnt.find(k) == mapKCnt.end()) {
                        mapKCnt[k] = 2;
                    }
                    else {
                        mapKCnt[k]++;
                    }
                    curMax = max(curMax, sameCnt + mapKCnt[k]);
                    //                    cout << "curMax:" << curMax << endl;
                    
                }
            }
            res = max(res, curMax);
        }
        return res;
    }
};

int main() {
    Solution sol;
    
    vector<Point> v;
    int res;
    
    v.push_back(Point(1,1));
    v.push_back(Point(1,1));
    v.push_back(Point(2,2));
    v.push_back(Point(2,2));
    res = sol.maxPoints(v);
    cout << res << endl;
    
    return 0;
}

