class Solution {
  
    int fun(int n, int m, int i, int j, vector<vector<int>> &og, vector<vector<int>> &v) {
    
        if(i >= n || j >= m || i < 0 || j < 0 || og[i][j] == 1) return 0;
        if(!i && !j) return 1;

        if(v[i][j] != -1) return v[i][j];

        int u = fun(n, m, i - 1, j, og, v),
            l = fun(n, m, i, j - 1, og, v);
        return v[i][j] = l + u;
    }

public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> v(m + 1, vector<int>(n + 1, -1));
        return fun(m, n, m - 1, n - 1, obstacleGrid, v);
    }
};