class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2)  {
        map<int, int> freq;
        for(int x : nums1) freq[x]++;
        vector<int> v;
        for(int x : nums2) if(freq[x] > 0) v.push_back(x), freq[x]--;
        return v;
    }
};