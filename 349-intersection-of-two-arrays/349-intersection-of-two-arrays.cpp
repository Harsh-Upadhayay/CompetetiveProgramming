class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set s(nums1.begin(), nums1.end());
        vector<int> v;
        for(int x : nums2) if(s.count(x)) v.push_back(x), s.erase(x);
        return v;
    }
};