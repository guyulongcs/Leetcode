#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;


class NestedIterator {
    int i=0;
    vector<int> v;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);
    }
    
    void dfs(vector<NestedInteger> &nestedList) {
        for(int i=0; i < nestedList.size(); i++) {
            if(nestedList[i].isInteger()) {
                v.push_back(nestedList[i].getInteger());
            }
            else {
                dfs(nestedList[i].getList());
            }
        }
    }
    
    int next() {
        return v[i++];
    }
    
    bool hasNext() {
        return i < v.size();
    }
    
};

//int main() {
//    
//    Solution s;
//    
//    return 0;
//}
