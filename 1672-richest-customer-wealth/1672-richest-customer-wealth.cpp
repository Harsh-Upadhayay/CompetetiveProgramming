class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        for(vector<int> account : accounts) {
            int cur_w = 0;
            for(int w : account)
                cur_w += w;
            ans = max(ans, cur_w);
        }
        return ans;
    }
};