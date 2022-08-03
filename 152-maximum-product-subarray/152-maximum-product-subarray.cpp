class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxP = nums[0], minP = nums[0], maxTN = nums[0], minTN = nums[0];
        bool flag = true;
        for(auto x : nums)
            if(x) flag = false;
        if(flag) {
            return 0;
        }
        for(int i = 1; i < nums.size(); i++) {
            auto x = nums[i];
            if(x  == 0) {
                maxTN = max(maxTN, maxP);
                minTN = min(minTN, minP);
                maxP = 1, minP = 1;
                maxTN = max(maxTN, x);
                continue;
            }
            if(x < 0)
                swap(maxP, minP);
            maxP = max(maxP * x, x); 
            minP = min(minP *x, x);
            
            maxTN = max(maxP, maxTN);
        }
        
        return maxTN;
    }
};