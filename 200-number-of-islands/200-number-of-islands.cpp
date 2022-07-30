class Solution {
    
    map<pair<int, int>, list<pair<int, int>>> graph;
    set<pair<int, int>> visited;
    
    void addEdge(int i, int j, int u, int v) {
        graph[{i, j}].push_back({u, v});
        if(u != -1 && v != -1)
            graph[{u, v}].push_back({i, j});
    }
    
    void build(vector<vector<char>> &grid) {
        
        graph.clear();
        visited.clear();
        int n = grid.size(), m = grid[0].size();
        map<pair<int, int>, list<pair<int, int>>> graph;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) 
                if(grid[i][j] == '1') {
                    bool isolated = true;
                    if(i != 0     && grid[i - 1][j] == '1') addEdge(i, j, i - 1, j), isolated = false;
                    if(i != n - 1 && grid[i + 1][j] == '1') addEdge(i, j, i + 1, j), isolated = false;
                    if(j != m - 1 && grid[i][j + 1] == '1') addEdge(i, j, i, j + 1), isolated = false;
                    if(j != 0     && grid[i][j - 1] == '1') addEdge(i, j, i, j - 1), isolated = false;
                    if(isolated) addEdge(i, j, -1, -1);
                }       
    }
    
    void dfs(pair<int, int> source) {
        if(visited.count(source))
            return;
        visited.insert(source);
        
        for(auto node : graph[source])
            dfs(node);
    }
    
public:
    
    int numIslands(vector<vector<char>>& grid) {
        
        build(grid);
        
        int islands = 0;
        for(auto node : graph) 
            if(!visited.count(node.first))
                dfs(node.first), islands++;
        
        return islands;
    }
};