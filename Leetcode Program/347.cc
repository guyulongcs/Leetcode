#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;

typedef unordered_map<int, int> MapCounter;
typedef unordered_map<int, int>::iterator MapCounterIter;
typedef pair<int, int> PairIntInt;

class Pair{
    
public:
    int first;
    int second;

    Pair(int f, int s) {
        first = f;
        second = s;
    }
    
    static bool less( Pair p1, Pair p2) {
        return p1 < p2;
    }
    
    static bool greater( Pair p1, Pair p2) {
        return p1 > p2;
    }
    
    bool operator >  (const Pair& p2) const{
        return second > p2.second;
    }
    
    bool operator <  (const Pair& p2) const{
        return second < p2.second;
    }
    
    
};



class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        MapCounter map = mapVectorCnt(nums);
        
        vector<Pair> pairVec = getPairVec(map);
        vector<int> res = topKFrequentOfMap(pairVec, k);
        
        return res;
    }
    
    MapCounter mapVectorCnt(vector<int> nums) {
        unordered_map<int, int> map;
        for(int i=0; i < nums.size(); i++) {
            int num = nums[i];
            if(map.find(num) == map.end())
                map[num] = 0;
            map[num] += 1;
        }
        return map;
    }
    
    vector<Pair> getPairVec(MapCounter map) {
        vector<Pair> pairVec;
        for(MapCounterIter it = map.begin(); it != map.end(); it++) {
            pairVec.push_back(Pair(it->first, it->second));
        }
        return pairVec;
    }
    
    
    //sort
    vector<int> topKFrequentOfMap1(MapCounter map, int k) {
        
        vector<int> values;
        
        for(MapCounterIter it = map.begin(); it != map.end(); it++) {
            values.push_back(it->second);
        }
        sort(values.begin(), values.end());
        int pos = values.size() - k;
        int threshold = values[pos];
        vector<int> res = vector<int>();
        for(MapCounterIter it = map.begin(); it != map.end(); it++) {
            if(it->second >= threshold)
                res.push_back(it->first);
        }
        return res;
    }
    
    static bool Compare(pair<int, int> p1, pair<int, int> p2) {
        return p1.second > p2.second;
    }
    
    //sort
    vector<int> topKFrequentOfMap2(MapCounter map, int k) {
        vector<pair<int,int> > v;
        
        for(MapCounterIter it = map.begin(); it != map.end(); it++) {
            v.push_back(pair<int,int>(it->first, it->second));
        }
        
        sort(v.begin(), v.end(), Compare);
        
        vector<int> res = vector<int>();
        
        for(int i=0; i < k; i++) {
            res.push_back(v[i].first);
        }
        
        return res;
    }
    
    
    
    //heap
    vector<int> topKFrequentOfMap3(vector<Pair>& vecPair, int k) {
        
        make_heap(vecPair.begin(), vecPair.begin()+k, less<Pair>());
        for(int i=k; i< vecPair.size(); i++) {
            Pair pair = vecPair[i];
            if(pair > vecPair[0]) {
                pop_heap(vecPair.begin(), vecPair.begin()+k, less<Pair>());
                vecPair[k-1] = pair;
                push_heap(vecPair.begin(), vecPair.begin()+k, less<Pair>());
            }
        }
        vector<int> topKRes = vector<int>();
        
        for(int i = 0; i<k; i++){
            topKRes.push_back(vecPair[i].first);
        }
        return topKRes;
    }
    
    
    //heap2
    vector<int> topKFrequentOfMap4(vector<Pair>& vecPair, int k) {
        
        
        vector<Pair> res;
        
        int i = 0;
        for(int index=0; index < vecPair.size(); index++) {
            Pair pair = vecPair[index];
            i++;
            if(i <= k) {
                res.push_back(pair);
            }
            if (i == k) {
                make_heap(res.begin(), res.end(), less<Pair>());
            }
            if(i > k) {
                if(pair > res[0]) {
                    res[0]=pair;
                    pop_heap(res.begin(), res.end(), less<Pair>());
                    res.pop_back();
                    
                    res.push_back(pair);
                    push_heap(res.begin(), res.end(), less<Pair>());
                }
            }
            
        }
        
        vector<int> topKRes = vector<int>();
        
        for(int i = 0; i<res.size(); i++){
            topKRes.push_back(res[i].first);
        }
        
        
        return topKRes;

    }
    
    
    
    //priority_queue
    vector<int> topKFrequentOfMap(vector<Pair> vecPair, int k) {
        
        priority_queue<Pair, vector<Pair>, less<Pair> > pq;
        
        for(int i=0; i < vecPair.size(); i++){
            Pair pair = vecPair[i];
            pq.push(pair);
            
        }
        
        vector<int> topKRes = vector<int>();
        
        
        for(int i = 0; i<k; i++){
            topKRes.push_back(pq.top().first);
            pq.pop();
        }
        
        
        return topKRes;
    }
    

    
};
int main() {
    int a[] = {1, 1, 1, 2, 4, 3, 2};
    vector<int> v(a, a+sizeof(a)/sizeof(int));
    
    Solution s = Solution();
    vector<int> res = s.topKFrequent(v, 2);
    
    for(int i=0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    
    
    
    
}

