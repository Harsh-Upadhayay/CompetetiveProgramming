class Solution {
    vector<vector<int>> ans;
    
    void genSubsets(vector<int> &seq, vector<int> &subseq, int idx = 0) {
        
        if(idx == seq.size()) {
            ans.push_back(subseq);
            return;
        }
        
        subseq.push_back(seq[idx]);
        genSubsets(seq, subseq, idx + 1);
        
        subseq.pop_back();
        genSubsets(seq, subseq, idx + 1);
        
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> sub;
        genSubsets(nums, sub);
        return ans;        
    }
};