class Solution {
    
    map<int, vector<int>> buildGraph(vector<vector<int>> &edges) {
        
        map<int, vector<int>> graph;
        
        for(auto uv : edges) 
            graph[uv[0]].push_back(uv[1]),
            graph[uv[1]].push_back(uv[0]);
        
        return graph;
    }
    
    void dfs (map<int, vector<int>> &adj, int source, int destination,
             vector<bool> &visited, bool &chk) {
        
        visited[source] = true;
        chk = chk || (source == destination);
        
        for(int node : adj[source])
            if(!visited[node])
                dfs(adj, node, destination, visited, chk);
    }
    
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        map<int, vector<int>> adj = buildGraph(edges);
        vector<bool> visited(n, false);
        bool chk = false;
        
        // for(auto x : adj) {
        //     cout << x.first << " : ";
        //     for(auto y : x.second)
        //         cout << y << " ";
        //     cout << "\n";
        // }
        
        
        dfs(adj, source, destination, visited, chk);
        
        return chk;        
    }
};