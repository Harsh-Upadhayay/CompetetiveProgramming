class Solution {
    
    void print(vector<int> v){
        
        for(auto x : v) cout << x << " ";
        cout << endl;
        
    }
    
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> lp(n), rp(n), pws(n);
        
        lp[0] = nums[0];
        for(int i = 1; i < n; i++)
            lp[i] = lp[i - 1] * nums[i];
    
        
        rp[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0; i--)
            rp[i] = rp[i + 1] * nums[i];
        
        pws[0] = rp[1],
        pws[n - 1] = lp[n - 2];
        
        for(int i = 1; i < n - 1; i++)
            pws[i] = lp[i - 1] * rp[i + 1];
        
        return pws;
        
    }
};