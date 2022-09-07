class Solution {
    
    map<string, vector<pair<string, double>>> graph;
    double val;
    bool flag;
    
    void buildGraph(vector<vector<string>>& equations, vector<double>& values) {
        
        for(int i = 0; i < values.size(); i++) 
            graph[equations[i][0]].push_back({equations[i][1], values[i]}),
            graph[equations[i][1]].push_back({equations[i][0], 1 / values[i]});        
    }
    
    void dfs(string s, string e, set<string> &vis, double weight = 1) {
        
        if(vis.count(s) || flag) return;
        cout << s << " ";
        vis.insert(s);
        if(s == e && graph[s].size()) {
            flag = true;
            val = weight;
            return;
        }
        
        for(auto node : graph[s]) 
            dfs(node.first, e, vis, weight*node.second);
        
        
    }
    
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        vector<double> result;
        buildGraph(equations, values);
        
        // for(auto x : graph) {
        //     for(auto y : x.second)
        //         cout << x.first << " / " << y.first << " = " << y.second << "\n";
        // }
        
        for(vector<string> query : queries) {
            val = 1, flag = false;
            set<string> vis;
            dfs(query[0], query[1], vis, val);
            
            if(flag)
                result.push_back(val);
            else
                result.push_back(-1);
            
        }
        
        return result;
    }
};
