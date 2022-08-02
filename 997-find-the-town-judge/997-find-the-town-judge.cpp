class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> graph[n + 1];
        for(int i = 0; i < trust.size(); i++)
            graph[trust[i][0]].push_back(trust[i][1]);
        vector<int> indegree(n + 1, 0);
        
        for(int i = 1; i <= n; i++)
            for(int j = 0; j < graph[i].size(); j++)
                indegree[graph[i][j]]++;
        
        int ans = -1;
        for(int i = 1; i <= n; i++)
            if(indegree[i] == n -1 && graph[i].size() == 0)
                ans = i;
        return ans;
    
    }
};