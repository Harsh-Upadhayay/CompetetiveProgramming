class Solution {
 
    
public:
    int rob(vector<int>& nums) {
        
        int pprev, prev, curr;
        
        if(nums.size() == 1) return nums[0];
        
        pprev = nums[0];
        prev = max(nums[0], nums[1]);
        
        for(int i = 2; i < nums.size(); i++) {
            
            int rob, notrob;
            rob = nums[i] + pprev;
            notrob = prev;

            curr = max(rob, notrob),
            pprev = prev,
            prev = curr;
        }
            
        
        return prev;
    }
};