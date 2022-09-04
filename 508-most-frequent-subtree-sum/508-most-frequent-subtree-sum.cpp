/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    unordered_map<int, int> freq;
    
    int sum(TreeNode *root) {
        
        if(!root) return 0;
        
        int l = sum(root -> left),
            r = sum(root -> right);
        
        root -> val += l + r;
        freq[root -> val]++;
        return root -> val;
    }
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        int hf = 0;
        vector<int> v;
        sum(root);
        for(pair<int, int> x : freq) hf = max(hf, x.second);
        for(pair<int, int> x : freq) if(x.second == hf) v.push_back(x.first);
        return v;
    }
};