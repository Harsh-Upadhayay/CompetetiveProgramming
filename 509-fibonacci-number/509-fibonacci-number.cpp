class Solution {
    int dp[100000];
public:
    Solution(){
        for(int i = 0; i < 100000; i++)
            dp[i] = -1;
    }
    int fib(int n) {
        if(dp[n] == -1)
            if(n <= 1)
                dp[n] = n;
            else
                dp[n] = fib(n-1) + fib(n-2);
        
        return dp[n];
    }
};