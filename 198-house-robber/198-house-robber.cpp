class Solution {
    
    int cost(vector<int> &nums, vector<int> &dp) {
          
        dp[0] = nums[0];
        if(nums.size() > 1) dp[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < nums.size(); i++) {
            
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            
        }
        return dp[nums.size() - 1];
    }
    
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        
        return cost(nums, dp);
    }
};
// 1 2 3 1
// 0 1 2 3