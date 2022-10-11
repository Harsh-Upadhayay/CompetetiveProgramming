class Solution {
 
    
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1) return nums[0];
        
        int pprev = nums[0], prev = max(nums[0], nums[1]), curr;
        
        for(int i = 2; i < nums.size(); i++) 
            
            curr = max(nums[i] + pprev, prev),
            pprev = prev,
            prev = curr;
                    
        
        return prev;
    }
};