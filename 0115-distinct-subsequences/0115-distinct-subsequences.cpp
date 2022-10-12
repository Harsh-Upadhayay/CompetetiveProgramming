
class Solution {

//     int f(string s, string t, vector<vector<int>> &dp, int i, int j) {
//         if(j == -1) return 1;
//         if(i < j) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
        
//         int take = (s[i] == t[j] ? f(s, t, dp, i - 1, j - 1) : 0);
        
//         return dp[i][j] = take + f(s, t, dp, i - 1, j);
//     }
    
    public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));
        
        for(int i = 0; i <= n; i++)
            dp[i][0] = 1;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(i < j) {dp[i][j] = 0; continue;}
                int take = (s[i - 1] == t[j - 1] ? dp[i - 1][j - 1] : 0);

                dp[i][j] = take + dp[i - 1][j];
            }
        }
        
        return (int)dp[n][m];
    }
};