class Solution {
   
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        
        dp[n - 1] = 0;
        
        for(int i = n - 2; i >= 0; i--) {
            
            int ans = 10e8;
            for(int j = 1; j <= nums[i]; j++) 
                if(i + j < n) ans = min(1 + dp[i + j], ans);

            dp[i] = ans;
        }
        
        return dp[0];        
    }
};