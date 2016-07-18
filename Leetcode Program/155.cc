#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <stack>


using namespace std;

class MinStack {
    stack<int> s;
    stack<int> smin;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(smin.empty() || (smin.top() >= x)) {
            smin.push(x);
        }
    }
    
    void pop() {
        if(s.empty())
            return;
        int x = s.top();
        s.pop();
        if(!smin.empty()) {
            if(smin.top() == x) {
                smin.pop();
            }
        }
    }
    
    int top() {
        if(s.empty())
            return 0;
        else
            return s.top();
    }
    
    int getMin() {
        if(smin.empty())
            return 0;
        else
            return smin.top();
    }
};


int main() {

    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.getMin() << endl;


    return 0;
}

