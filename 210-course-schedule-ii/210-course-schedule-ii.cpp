class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> graph[numCourses],indegree(numCourses, 0);
        for(auto x : prerequisites)
            graph[x[1]].push_back(x[0]), indegree[x[0]]++;
        
        for(int i = 0; i < numCourses; i++) {
            cout << i <<" : ";
            for(auto x: graph[i]) cout << x << " ";
            cout << "\t" << indegree[i] << "\n";            
        }
        
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i < numCourses; i++)
            if(!indegree[i]) q.push(i), ans.push_back(i);
        
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            for(auto x : graph[curr]) {
                indegree[x]--;
                if(!indegree[x]) q.push(x), ans.push_back(x);
            }
            
        }
        if(ans.size() != numCourses) ans.clear();
        return ans;
    }

};