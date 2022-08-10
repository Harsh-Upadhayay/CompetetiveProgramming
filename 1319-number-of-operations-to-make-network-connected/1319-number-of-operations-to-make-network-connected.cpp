class Solution {
    void dfs(vector<vector<int>> &graph,
             vector<int>         &visited,
             map<int, int>            &groups,
             int                  source,
             int                 parent,
             int                 group) {
        
        visited[source] = group;
        
        for(int x : graph[source]) {
            if(!visited[x])
                dfs(graph, visited, groups, x, source, group);
            else if(parent != x)
                groups[group]++;
        }
        
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        map<int, int> groups;
        vector<int> visited(n, 0);
        vector<vector<int>> graph(n, vector<int>());
        for(auto x : connections)
            graph[x[0]].push_back(x[1]),
            graph[x[1]].push_back(x[0]);
        int k = 1, t = -1;
        // for(int i = 0; i < n; i++) {
        //     cout << i << " : ";
        //     for(auto x : graph[i])
        //         cout << x << " ";
        //     cout << "\n";
        // }   
        for(int i = 0; i < n; i++)
            if(!visited[i])
                dfs(graph, visited, groups, i, t, k++);
        // for(auto x : groups)
        //     cout << x.first << " " << x.second << "\n";
        map<int, int> freq;
        for(auto x : visited)
            freq[x]++;
        int edg_req = freq.size() - 1,
            edg_avil = 0;
        for(auto x : groups)
            edg_avil += (x.second/2);
        cout << edg_avil;
        
        return (edg_avil >= edg_req) ? edg_avil - (edg_avil - edg_req): -1;
    }
};