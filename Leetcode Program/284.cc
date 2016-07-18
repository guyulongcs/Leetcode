#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;


// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
private:
    bool flagHasNext;
    int nextVal;
    int peekval();
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        this->next();
    }
    
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return nextVal;
    }
    
    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int ret = nextVal;
        if(Iterator::hasNext()) {
            flagHasNext = true;
            nextVal = Iterator::next();
        }
        else {
            flagHasNext = false;
        }
        return ret;
    }
    
    bool hasNext() const {
        return flagHasNext;
    }
};

int main() {

    int res=0;
    cout << res << endl;

    return 0;
}

