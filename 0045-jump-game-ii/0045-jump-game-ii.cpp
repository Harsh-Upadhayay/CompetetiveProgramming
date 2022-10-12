class Solution {
    
    int f(vector<int> &nums, vector<int> &dp, int i) {
        if(i >= nums.size() - 1)
            return 0;
        if(dp[i] != -1) return dp[i];
        
        int ans = 10e8;
        for(int j = 1; j <= nums[i]; j++) 
            ans = min(1 + f(nums, dp, i + j), ans);
        

        return dp[i] = ans;
    }
    
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return f(nums, dp, 0);        
    }
};