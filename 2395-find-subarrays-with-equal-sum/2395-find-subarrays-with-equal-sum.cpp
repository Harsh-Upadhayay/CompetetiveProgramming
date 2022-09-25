class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        
        map<int, vector<int>> subsum;
        for(int i = 0; i < nums.size() - 1; i++) 
            subsum[nums[i] + nums[i + 1]].push_back(i);
        
        for(int i = 0; i < nums.size() - 1; i++)
            for(int st_idx : subsum[nums[i] + nums[i + 1]])
                if(st_idx != i)
                    return true;
        
        return false;
    }
};