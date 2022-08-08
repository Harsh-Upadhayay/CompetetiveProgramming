class Solution {
    void dfs(vector<vector<int>>& rooms, vector<bool> &visited, int start) {
        if(visited[start])
            return;
        visited[start] = true;
        for(auto adj : rooms[start])
            dfs(rooms, visited, adj);
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        dfs(rooms, visited, 0);
        bool flag = true; for(auto x : visited) flag &= x;
        return flag;
    }
};