class Solution {
    
public:
    int rob(vector<int>& nums) {
        
        int n   = nums.size();
        
        if(n == 2)
            return max(nums[0], nums[1]);
        if(n == 1) 
            return nums[0];
        
        int
            nm2 = nums[0],
            nm1 = max(nums[0], nums[1]), 
            curr = nm2;
        
        for(int i = 2; i < n; i++) 
            
            curr = max(nm1, nm2 + nums[i]),
            nm2 = nm1,
            nm1 = curr;
            
        return curr;
    }
};
// 1 2 3 1
// 0 1 2 3