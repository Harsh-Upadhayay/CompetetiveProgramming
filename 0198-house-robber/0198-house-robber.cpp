class Solution {
    
    int f(vector<int> &nums, vector<int> &dp, int i) {
        if(i == 0) return nums[0];
        if(i == 1) return max(nums[0], nums[1]);
        if(dp[i] != -1) return dp[i];
        
        int rob, notrob;
        rob = nums[i] + f(nums, dp, i - 2);
        notrob = f(nums, dp, i - 1);
        
        return dp[i] = max(rob, notrob);
    } 
    
public:
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size(), -1);
        
        return f(nums, dp, nums.size() - 1);
    }
};