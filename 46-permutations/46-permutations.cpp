class Solution {
    
    vector<vector<int>> permutations;
    vector<int> permutation;
    set<int> used_idx;
    
    
    
    void genPerm(vector<int> &v) {
        
        if(used_idx.size() == v.size()) {
            permutations.push_back(permutation);
            return;
        }
        
        for(int i = 0; i < v.size(); i++) {
            if(!used_idx.count(i)) {
                used_idx.insert(i);
                permutation.push_back(v[i]);
                genPerm(v);
                used_idx.erase(i);
                permutation.pop_back();
            }
            
        }
        
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        used_idx.clear();
        genPerm(nums);
        return permutations;
    }
};