class Solution {
    int ans;
    void f(vector<int> &arr, vector<int> &vis, int s) {
        if(s < 0 || s >= arr.size() || vis[s]) return;
        vis[s] = 1;
        ans |= !arr[s];
        // cout << s << " " << ans << "\n";
        f(arr, vis, s + arr[s]);
        f(arr, vis, s - arr[s]);
    }
    
public:
    bool canReach(vector<int>& arr, int start) {
        ans = 0;
        vector<int> vis(arr.size(), 0);
        f(arr, vis, start);
        return ans;
    }
};