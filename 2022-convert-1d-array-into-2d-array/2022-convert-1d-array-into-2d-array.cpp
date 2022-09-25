class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> ans;
        if(m * n != original.size()) return ans;
        int j = 1;
        vector<int> v;
        for(int i = 0; i < original.size(); i++) {
            if(j > n) ans.push_back(v), j = 1, v.clear();
            j++, v.push_back(original[i]);
        }
        ans.push_back(v);
        return ans;
    }
};