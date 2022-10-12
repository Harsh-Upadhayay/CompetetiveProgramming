class Solution {

int f(string &t, string &s, vector<vector<long long int>> &dp, int i, int j) {
    
    if(j == -1) return 1;
    if(i < j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    
    long long int take = 0;
    if(t[i] == s[j]) take = f(t, s, dp, i - 1, j - 1);
       
    return dp[i][j] = (take + f(t, s, dp, i - 1, j));
}

public:
    int numDistinct(string s, string t) {
        swap(s, t);
        int ls = s.size(), lt = t.size();
        vector<vector<long long int>> dp(lt, vector<long long int> (ls, -1));
        return f(t, s, dp, lt - 1, ls - 1);
    }
};