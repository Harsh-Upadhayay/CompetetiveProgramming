class Solution {
    vector<vector<int>> ans;
    void dfs(vector<vector<int>> &graph, int source, vector<int> path){
        
        path.push_back(source);
        if(source == graph.size() - 1) { 
            ans.push_back(path);
        }
        
        for(int x : graph[source]){
            cout << x;
            dfs(graph, x, path);
        }
        
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        ans.clear();
        
        vector<int> path;
        dfs(graph, 0, path);
        return ans;
    }
};