class Solution {
    
    vector<vector<int>> ans;
    
    void comb_sum(vector<int> &seq, vector<int> &subseq, int tgt, int idx = 0, int sum = 0) {
        
        if(sum > tgt) return;
        if(idx == seq.size()) {
            if(sum == tgt) {
                vector<int> v(subseq.begin(), subseq.end());
                ans.push_back(v);
            }
            return;
        }
        
        subseq.push_back(seq[idx]);
        sum += seq[idx];
        
        comb_sum(seq, subseq, tgt, idx, sum); 
        
        subseq.pop_back();
        sum -= seq[idx];
        
        comb_sum(seq, subseq, tgt, idx + 1, sum);
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> subseq;
        comb_sum(candidates, subseq, target);
        
        return ans;
    }
};