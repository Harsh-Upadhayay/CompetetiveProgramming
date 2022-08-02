class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> graph[n + 1];
        for(auto x : trust)
            graph[x[0]].push_back(x[1]);
        vector<int> indegree(n + 1, 0);
        
        for(int i = 1; i <= n; i++)
            for(auto x : graph[i])
                indegree[x]++;
        
        int ans = -1;
        for(int i = 1; i <= n; i++)
            // cout << indegree[i] << " ";
            if(indegree[i] == n -1 && graph[i].size() == 0)
                ans = i;
        return ans;
    
    }
};