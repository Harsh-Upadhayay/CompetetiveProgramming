class Solution {
    void dfs(map<int, vector<int>> &graph, vector<int> &visited, int s, int g) {
        if(visited[s])
            return;
        visited[s] = g;
        for(auto u : graph[s])
            dfs(graph, visited, u, g);
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> visited(n, 0);
        int g = 1;
        map<int, vector<int>> graph;
        for(auto edge : edges)
            graph[edge[0]].push_back(edge[1]),
            graph[edge[1]].push_back(edge[0]);
        
        for(int i = 0; i < n; i++)
            if(!visited[i])
                dfs(graph, visited, i, g++);
        
        map<int, int> freq;
        for(auto x : visited)
            freq[x]++;
        
        long long ans = 0;
        for(auto x : visited)
            ans += (n - freq[x]);
        
        return ans/2;
    }
};