class Solution {
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