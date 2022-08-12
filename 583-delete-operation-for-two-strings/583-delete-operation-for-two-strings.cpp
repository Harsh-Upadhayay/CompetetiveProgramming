class Solution {
    int lcs(string a, string b, int n, int m, vector<vector<int>> &dp) {
        if(!n || !m)
            return 0;
        if(dp[n][m] == -1) {
            if(!n || !m)
                dp[n][m] = 0;
            else if(a[n - 1] == b[m - 1])
                dp[n][m] = 1 + lcs(a, b, n - 1, m - 1, dp);
            else dp[n][m] = max(lcs(a, b, n - 1, m, dp), lcs(a, b, n, m - 1, dp));
        }
        return dp[n][m];
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int c = lcs(word1, word2, n, m, dp);
        return n - c + m - c;
    }
};