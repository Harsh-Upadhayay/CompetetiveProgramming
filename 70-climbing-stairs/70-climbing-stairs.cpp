class Solution {
    int dp[1000000];
public:
    Solution() {
        memset(dp, -1, 1000000);
    }
    int climbStairs(int n, int i = 0) {
        if(i > n) return 0;
        if(dp[i] == -1) { 
            if(i == n) dp[i] = 1;
            else dp[i] = climbStairs(n, i + 1) + climbStairs(n, i + 2);
        }
        return dp[i];
    }
};