class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int maxE = INT_MIN;
        for(auto x : nums) maxE = max(maxE, x);
        if(maxE <= 0) return maxE;
        
        int maxSum = INT_MIN, curSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            
            if(curSum + nums[i] < nums[i])
                 curSum = nums[i];
            else 
                curSum += nums[i];
            maxSum = max(curSum, maxSum);
            // cout << maxSum << " ";
        }
        
        return maxSum;
    }
};