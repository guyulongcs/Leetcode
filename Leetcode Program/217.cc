
class Solution {
public:
bool containsDuplicate(vector<int>& nums) {
    bool flag=false;
     unordered_set<int> hSet;
    
    for(vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
        int n = (*it);
        if(hSet.find(n) != hSet.end()) {
            flag=true;
            break;
        }
        else{
            hSet.insert(*it);
        }
    }
    
    return flag;
}
};
