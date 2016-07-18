#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>

#include <algorithm>

using namespace std;

class Queue {
private:
    stack<int> si;
    stack<int> so;
public:
    Queue() {
        
    }
    // Push element x to the back of queue.
    void push(int x) {
        si.push(x);
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        tranferSI2SO();
        if(!so.empty()) {
            so.pop();
        }
    }
    
    void tranferSI2SO() {
        if(so.empty()) {
            while(!si.empty()) {
                so.push(si.top());
                si.pop();
            }
        }
    }
    
    // Get the front element.
    int peek(void) {
        tranferSI2SO();
        if(so.empty()) {
            return 0;
        }
        else {
            return so.top();
        }
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        tranferSI2SO();
        return so.empty();
    }
};


int main() {
    Queue s;
    s.push(1);
    s.push(3);
    cout << s.peek() << endl;
    s.push(2);
    while(!s.empty()) {
        cout << s.peek() << endl;
        s.pop();
    }
    
    return 0;
}

