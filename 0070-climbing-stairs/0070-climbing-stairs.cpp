class Solution {
    
//     int f(int i, vector<int> &dp) {
//         if(i == 0) return 1;
//         if(i < 0) return 0;
//         if(dp[i] != -1) return dp[i];
//         return dp[i] = f(i - 1, dp) + f(i - 2, dp);
//     }
    
public:
    int climbStairs(int n) {
        int prev = 1, pprev = 0, curr = 0;
        for(int i = 1; i <= n; i++) 
            curr = prev + pprev,
            pprev = prev, 
            prev = curr;
        
        return prev;
    }
};