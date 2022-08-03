class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftp(n, 0), rightp(n, 0);
        leftp[0] = 1;
        for(int i = 1; i < n; i++)
            leftp[i] = leftp[i - 1] * nums[i - 1];
        rightp[n - 1] = 1;
        for(int i = n - 2; i >= 0; i--)
            rightp[i] = rightp[i + 1] * nums[i + 1];
        vector<int> ans(n);
        for(int i = 0; i < n; i++)
            ans[i] = leftp[i] * rightp[i];
        for(auto x : leftp)
            cout << x << " ";
        cout << "\n";
        for(auto x : rightp)
            cout << x << " ";
        return ans;
    }
};