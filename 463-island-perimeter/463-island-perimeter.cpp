class Solution {
    int perimeter;
    
    void dfs(vector<vector<int>> &grid, vector<vector<int>> &visited, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || !grid[i][j] || visited[i][j])
            return;
        
        visited[i][j] = 1;
        
        perimeter += (i == 0                  || !grid[i - 1][j])
                  +  (i == grid.size() - 1    || !grid[i + 1][j])
                  +  (j == 0                  || !grid[i][j - 1])
                  +  (j == grid[0].size() - 1 || !grid[i][j + 1]);
        cout << i << " " << j << " " << perimeter << "\n";
        dfs(grid, visited, i - 1, j);
        dfs(grid, visited, i + 1, j);
        dfs(grid, visited, i, j - 1);
        dfs(grid, visited, i, j + 1);
    }
    
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        perimeter = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1) {
                    dfs(grid, visited, i, j);
                        break;
                }
            }
        }
        return perimeter;        
    }
};