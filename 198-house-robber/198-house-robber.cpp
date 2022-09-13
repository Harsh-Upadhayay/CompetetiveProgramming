class Solution {
    
    int cost(vector<int> &nums, vector<int> &dp, int i) {
          
        if(i < 0) return 0;
        if(i == 0) return nums[0];
        
        if(dp[i] != -1) return dp[i];
        
        int l = cost(nums, dp, i - 1);
        int r = cost(nums, dp, i - 2) + nums[i];        
        
        return dp[i] = max(l, r);
    }
    
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        
        return cost(nums, dp, nums.size() - 1);
    }
};
// 1 2 3 1
// 0 1 2 3