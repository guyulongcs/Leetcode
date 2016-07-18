#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
using namespace std;

class Tweet {
private:
    int tweetId;
    time_t timestamp;
public:
    Tweet() {
        
    }
    
    int getId() {
        return tweetId;
    }
    
    Tweet(int id=0, time_t t=0) {
        tweetId = id;
        timestamp = t;
    }
    
//    friend bool Cmp(const Tweet & t1, const Tweet & t2) {
//        bool flag = t1 < t2;
//        return flag;
//    }
    
    friend bool operator < (const Tweet & t1, const Tweet & t2) {
        return (t1.timestamp < t2.timestamp);
    }
    
    friend bool operator > (const Tweet & t1, const Tweet & t2) {
        return (t1.timestamp > t2.timestamp);
    }
};


class Twitter {
private:
    unordered_map<int, unordered_set<int> > fmap;
    unordered_map<int, list<Tweet> > tmap;
    long long tweetCnt=0;
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        time_t t = getCurTimeStamp();
        Tweet tweet = Tweet(tweetId, t);
        if(tmap.find(userId) == tmap.end()) {
            tmap[userId] = list<Tweet>() ;
        }
        tmap[userId].push_back(tweet);
        
        //cout << "tweetId, t:" << tweetId << "\t" << t << endl;
    }
    

    time_t getCurTimeStamp() {
        time_t t;
        //t = time(NULL);
        t = (time_t) tweetCnt;
        tweetCnt++;
        
        return t;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> v;
        priority_queue<Tweet, vector<Tweet>, less<Tweet>> pq;
        
        const int maxCnt = 10;
        addUserTweet(userId, pq, maxCnt);
        
        if(fmap.find(userId) != fmap.end()) {
            for(auto it=fmap[userId].begin(); it != fmap[userId].end(); it++) {
                addUserTweet(*it, pq, maxCnt);
            }
        }
        
        int cnt=0;
        while(!pq.empty()) {
            Tweet tweet = pq.top();
            pq.pop();
            v.push_back(tweet.getId());
            cnt++;
            if(cnt >= maxCnt) {
                break;
            }
        }
        
        
        return v;
    }
    
    void addUserTweet(int userId, priority_queue<Tweet, vector<Tweet>, less<Tweet>> & pq, int maxCnt) {
        if(tmap.find(userId) == tmap.end()) {
            return;
        }
        int cnt=0;
        
    
        
        int N = tmap[userId].size();
        maxCnt = min(maxCnt, N);
        
        if(N == 0)
            return;
        
        auto it = tmap[userId].end();
        it--;
        while(N) {
            pq.push(*it);
            it--;
            N--;
        }
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) {
            return;
        }
        if(fmap.find(followerId) == fmap.end()) {
            fmap[followerId] = unordered_set<int>();
        }
        fmap[followerId].insert(followeeId);
     }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(fmap.find(followerId) == fmap.end()) {
            return;
        }
        fmap[followerId].erase(followeeId);
    }
};

void printVecInt(vector<int> & v) {
    for(int i=0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout << endl;
}

int main() {


    Twitter obj = Twitter();
    vector<int> feeds;
    
    obj.postTweet(1,5);
    obj.postTweet(1,3);
    feeds = obj.getNewsFeed(1);
    printVecInt(feeds);
    
//    obj.follow(1,2);
//    obj.postTweet(2,6);
//    feeds = obj.getNewsFeed(1);
//    printVecInt(feeds);
//    
//    
//    obj.unfollow(1,2);
//    obj.getNewsFeed(1);
//    feeds = obj.getNewsFeed(1);
//    printVecInt(feeds);
    
    
    return 0;
}

