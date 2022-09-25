class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        set<int> sset;
        const int sx = nums[0].size();
        for(string x : nums)
            sset.insert(stoi(x, nullptr, 2));
        for(int i = 0; i < pow(2, nums[0].size()); i++)
            if(!sset.count(i))
                return bitset<16>(i).to_string().substr(16 - sx);
        return "";
    }
};