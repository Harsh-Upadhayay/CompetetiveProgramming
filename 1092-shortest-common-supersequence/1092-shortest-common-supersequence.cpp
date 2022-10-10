class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 0; j <= m; j++) dp[0][j] = 0;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        string ans = "";
        int i = n, j = m;
        
        for(auto x : dp) {
            for(auto y : x) cout << y << " ";
            cout << "\n";
        }
        
        while (i && j) {
            if(str1[i - 1] == str2[j - 1]) ans += str1[i - 1], i--, j--;
            else {
                if(dp[i - 1][j] > dp[i][j - 1]) i--, ans += str1[i];
                else j--, ans += str2[j];
            }
        }
        
        while(i--) ans += str1[i];
        while(j--) ans += str2[j];
        reverse(ans.begin(), ans.end());
        
        return ans;        
    }
};