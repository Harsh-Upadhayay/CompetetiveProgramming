class Solution {
    int *dp;
public:
    int _tribonacci(int n){
        
        if(n == 0 || dp[n])
            return dp[n];
        
        if(n == 1 || n == 2)
            dp[n] = 1;
        else
            dp[n] = _tribonacci(n-2) + _tribonacci(n-1) + _tribonacci(n-3);
        
        return dp[n];
    }
    int tribonacci(int n) {
        dp = (int*)calloc(n+1, sizeof(int));
        _tribonacci(n);
        return dp[n];
    }
};