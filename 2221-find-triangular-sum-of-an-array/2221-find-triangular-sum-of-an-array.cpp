class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> newNums(nums.size() - 1);
        
        for(int i = 0; i < newNums.size(); i++)
            newNums[i] = (nums[i] + nums[i+1]) % 10;
        
        return triangularSum(newNums);
    }
};