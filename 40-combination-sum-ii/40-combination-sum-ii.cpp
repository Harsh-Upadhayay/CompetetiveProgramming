class Solution {
    vector<vector<int>> ans;
    
    void comb_sum(vector<int> &seq, vector<int> &subseq, int tgt, int idx = 0) {
        
        
            if(!tgt) {
                vector<int> v(subseq.begin(), subseq.end());
                ans.push_back(v);
                return;
            }
        
        
        for(int i = idx; i < seq.size(); i++) {
            
            if(seq[i] > tgt) return;
            
            if(i != idx && seq[i] == seq[i -1 ]) continue;
            
            subseq.push_back(seq[i]);
            comb_sum(seq, subseq, tgt - seq[i], i + 1);
            subseq.pop_back();
            
        }
    }
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> subseq;
        sort(candidates.begin(), candidates.end());
        comb_sum(candidates, subseq, target);
        return ans;
    }


};