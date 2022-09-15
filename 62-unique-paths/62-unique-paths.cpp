class Solution {
  
    int fun(int n, int m, int i, int j, vector<vector<int>> &v) {
    
        if(i >= n || j >= m || i < 0 || j < 0) return 0;
        if(!i && !j) return 1;

        if(v[i][j] != -1) return v[i][j];

        int u = fun(n, m, i - 1, j, v),
            l = fun(n, m, i, j - 1, v);
        return v[i][j] = l + u;
    }

public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(m + 1, vector<int>(n + 1, -1));
        
        return fun(m, n, m - 1, n - 1, v);
    }
};