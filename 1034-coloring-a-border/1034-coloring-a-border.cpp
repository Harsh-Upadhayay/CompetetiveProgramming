class Solution {
    void dfs(vector<vector<int>> &grid, 
             vector<vector<int>> &soln, 
             vector<vector<int>> &v, 
             int row, int col, int color, int init) {
        
        if(   grid.size() <= row
           || grid[0].size() <= col 
           || row < 0
           || col < 0
           || v[row][col] 
           || grid[row][col] != init 
          )   return;
        
        v[row][col] = 1;
        
        if(   grid.size() - 1 == row 
           || grid[0].size() - 1 == col
           || 0 == row 
           || 0 == col
           || grid[row - 1][col] != init
           || grid[row + 1][col] != init
           || grid[row][col + 1] != init
           || grid[row][col - 1] != init
          )
            soln[row][col] = color;
        
        dfs(grid, soln, v, row - 1, col, color, init);
        dfs(grid, soln, v, row + 1, col, color, init);
        dfs(grid, soln, v, row, col + 1, color, init);
        dfs(grid, soln, v, row, col - 1, color, init);       
    }
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        
        vector<vector<int>> v(grid.size(), vector<int> (grid[0].size(), 0)),
                            soln(grid.size(), vector<int> (grid[0].size(), 0));
        
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                soln[i][j] = grid[i][j];
        
        dfs(grid, soln, v, row, col, color, grid[row][col]);
        
        return soln;
    }
};