class Solution {

    unordered_map<int, list<int>> graph;
    unordered_set<int> visited;
    
    void dfs(int node) {
        if(visited.count(node)) return;
        visited.insert(node);
        
        for(auto x : graph[node])
            dfs(x);
        
    }
    
    public:
    
    int findCircleNum(vector<vector<int>>& isConnected) {
            
        graph.clear();
        visited.clear();
        
        int n = isConnected.size();
        for(int i = 0; i < n; i++)
            for(int j =0; j < n; j++)
                if(isConnected[i][j])
                    graph[i].push_back(j);
        
        int dissConnected_components = 0;
        for(auto root : graph)
            if(!visited.count(root.first))
                dissConnected_components++, dfs(root.first);
        
        return dissConnected_components;
    }
};