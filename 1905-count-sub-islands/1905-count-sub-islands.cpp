class Solution {
    bool flag;
    void dfs(vector<vector<int>>& grid1,
             vector<vector<int>>& grid2,
             int i, int j) {
        
        if(i >= grid2.size() ||
           i < 0             ||
           j >= grid2[0].size() ||
           j < 0             ||
           !grid2[i][j] ) return;
        
        grid2[i][j] = 0;
        flag &= grid1[i][j] == 1;
        
        dfs(grid1, grid2, i + 1, j);
        dfs(grid1, grid2, i - 1, j);
        dfs(grid1, grid2, i, j + 1);
        dfs(grid1, grid2, i, j - 1);
        
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int count = 0;
        
        for(int i = 0; i < grid1.size(); i++) {
            for(int j = 0; j < grid1[0].size(); j++) {
                if(grid2[i][j]) {
                    flag = true;
                    dfs(grid1, grid2, i, j);
                    count += flag;
                }
            }
        }
        
        return count;
        
    }
};