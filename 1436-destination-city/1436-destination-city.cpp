class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> adj;
        
        for(auto path : paths) 
            adj.insert(path[0]);
        
        for(auto path : paths)
            if(!adj.count(path[1]))
                return path[1];
        
        return "Hi";
            
    }
};