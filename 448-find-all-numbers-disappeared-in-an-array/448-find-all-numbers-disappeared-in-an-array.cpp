class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
            int idx = nums[i] < 0 ? nums[i] * - 1 : nums[i];
            idx -= 1;
            nums[idx] *= nums[idx] < 0 ? 1 : -1;
        }
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++) if(nums[i] > 0) ans.push_back(i+1);
        return ans;
    }
};