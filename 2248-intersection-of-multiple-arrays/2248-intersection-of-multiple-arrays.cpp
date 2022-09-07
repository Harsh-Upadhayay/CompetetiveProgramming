class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        set<int> cmn_set(nums[0].begin(), nums[0].end());
        
        for(vector<int> array : nums) {
            set<int> cur_set(array.begin(), array.end());
            for(int num : cmn_set) {
                if(!cur_set.count(num))
                    cmn_set.erase(num);
            }
        }
        vector<int> ans;
        for(int x : cmn_set) ans.push_back(x);
        return ans;
    }
};