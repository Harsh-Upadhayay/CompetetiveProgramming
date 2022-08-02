class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> graph[numCourses],indegree(numCourses, 0);
        for(auto x : prerequisites)
            graph[x[1]].push_back(x[0]), indegree[x[0]]++;
        
        for(int i = 0; i < numCourses; i++) {
            cout << i <<" : ";
            for(auto x: graph[i]) cout << x << " ";
            cout << "\t" << indegree[i] << "\n";            
        }
        
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(!indegree[i]) q.push(i);
        
        int v = q.size();
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            for(auto x : graph[curr]) {
                indegree[x]--;
                if(!indegree[x]) q.push(x), v++;
            }
            
        }
        cout << v << "*\n";
        return v == numCourses;
    }
};