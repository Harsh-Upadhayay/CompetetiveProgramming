class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        vector<int> &v = nums;
        int flag = -1, n = nums.size();
        for(int i = n - 1; i > 0; i--) {
            if(v[i - 1] < v[i]) {flag = i - 1; break;}
        }
        // cout << flag;
        if(-1 == flag) {reverse(nums.begin(), nums.end()); return;}
        
        int minDiff = INT_MAX, idx;
        for(int i = flag + 1; i < n; i++) 
            if(v[flag] < v[i] && minDiff > v[i] - v[flag])
                minDiff = v[i] - v[flag], idx = i;
        
        swap(v[idx], v[flag]);
        for(auto x : v) cout << x << " ";
        sort(v.begin() + flag + 1, v.end());
        
    }
};