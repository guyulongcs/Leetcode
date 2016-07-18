#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


class Stack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    // Push element x onto stack.
    void push(int x) {
        if(q1.empty()) {
            push_num(q1, q2, x);
        }
        else {
            push_num(q2, q1, x);
        }
    }
    
    void push_num(queue<int>& q1, queue<int>& q2, int n) {
        q1.push(n);
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    
    // Removes the element on top of the stack.
    void pop() {
        if(!q1.empty()) {
            q1.pop();
        }
        else if(!q2.empty()) {
            q2.pop();
        }
    }
    
    // Get the top element.
    int top() {
        int res = -1;
        if(!q1.empty()) {
            res = q1.front();
        }
        else if(!q2.empty()) {
            res = q2.front();
        }
        return res;
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return (q1.empty() && q2.empty());
    }
};


int main() {
    Stack s;
    s.push(1);
    s.push(3);
    s.push(4);
    while(!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}

