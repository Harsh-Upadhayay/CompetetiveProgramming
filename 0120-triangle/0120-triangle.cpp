#define inf 1e8
class Solution {
    
    int f(vector<vector<int>>& arr, vector<vector<int>> &dp, int i, int j) {
        
        if(i == arr.size()) return 0;
        if(j == arr[i].size()) return inf;
        if(dp[i][j] != -1) return dp[i][j];
        
        int left = 0, right = 0;
        left = arr[i][j] + f(arr, dp, i + 1, j);
        right = arr[i][j] + f(arr, dp, i + 1, j + 1);
        
        return dp[i][j] = min(left, right);
    }
    
public:
    int minimumTotal(vector<vector<int>>& arr) {
        
        int n = arr.size();
        vector<int> cur(n + 1, 0), nxt(cur);
        
        for(int i = n - 1; i >= 0; i--, nxt = cur) 
            for(int j = i; j >= 0; j--) 
                cur[j] = min(arr[i][j] + nxt[j], arr[i][j] + nxt[j + 1]);
        
        return cur[0];
    }
};