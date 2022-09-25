class Solution {
    vector<vector<int>> ans;
    
    void genSubset(vector<int> &seq, vector<int> &subseq, int idx = 0) {
        if(idx == seq.size()) return;
        
        
        for(int i = idx; i < seq.size(); i++) {
            
            if(i != idx && seq[i] == seq[i - 1]) continue;
            
            subseq.push_back(seq[i]);
            ans.push_back(subseq);
            for(auto x : subseq) cout << x;
            cout <<"\n";
            genSubset(seq, subseq, i + 1);
            
            subseq.pop_back();
        }
                
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> sub;sort(nums.begin(), nums.end());
        ans.push_back(sub);
        genSubset(nums, sub);        
        return ans;
    }
};