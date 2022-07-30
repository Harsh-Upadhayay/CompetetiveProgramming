class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<vector<int>> &v = edges;
        int a = v[0][0], b = v[0][1], c = v[1][0], d = v[1][1];
        if(a == c || a == d) return a;
        else                 return b;
    }
};