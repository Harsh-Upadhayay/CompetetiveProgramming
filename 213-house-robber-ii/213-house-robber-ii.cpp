class Solution {
    
    int rob(vector<int>& nums, int l, int r) {
        
        int n   = r - l;
        
        if(n == 2)
            return max(nums[l + 0], nums[l + 1]);
        if(n == 1) 
            return nums[l + 0];
        
        int
            nm2 = nums[l + 0],
            nm1 = max(nums[l + 0], nums[l + 1]), 
            curr = nm2;
        
        for(int i = 2; i < n; i++) 
            
            curr = max(nm1, nm2 + nums[l + i]),
            nm2 = nm1,
            nm1 = curr;
            
        return curr;
    }
    
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
         return n > 2 ? max(rob(nums, 0, n - 1), rob(nums, 1, n)) : ((n == 1) ? nums[0] : max(nums[1], nums[0]));
    }
};