class Solution {
    
    bool f(vector<int> &nums, vector<int> &dp, int i) {
        if(i >= nums.size() - 1)
            return true;
        if(dp[i] != -1) return dp[i];
        
        bool ans = false;
        for(int j = 1; j <= nums[i]; j++) {
            if(ans) break;
            ans |= f(nums, dp, i + j);
        }
            
        
        return dp[i] = ans;
    }
    
public:
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return f(nums, dp, 0);
    }
};