class Solution {
 
    
public:
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size(), -1);
        
        if(nums.size() == 1) return nums[0];
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < nums.size(); i++) {
            
            int rob, notrob;
            rob = nums[i] + dp[i - 2];
            notrob = dp[i - 1];

            dp[i] = max(rob, notrob);
        }
            
        
        return dp[nums.size() - 1];
    }
};