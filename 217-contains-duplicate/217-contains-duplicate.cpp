class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        bool flag = false;
        for(auto x : nums)
            flag |= s.count(x), s.insert(x);
        
        return flag;
            
    }
};