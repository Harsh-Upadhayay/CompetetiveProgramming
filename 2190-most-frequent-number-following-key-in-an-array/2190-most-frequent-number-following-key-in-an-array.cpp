class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        map<int, int> freq;
        
        for(int i = 0; i < nums.size() - 1; i++)
            if(nums[i] == key) freq[nums[i + 1]]++;
        
        int targ = 0;
        for(auto x : freq) targ = max(targ, x.second);
        for(auto x : freq) if(x.second == targ) return x.first;
        return 0;
    }
};