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
    pair<int, bool> fun(TreeNode* root) {
        
        if(!root) return {0, true};
        
        auto l = fun(root -> left),
             r = fun(root -> right);
        
        int  lh = l.first,
             rh = r.first;
        
        bool lb = l.second,
             rb = r.second;       
        
        return {max(lh, rh) + 1, lb && rb && abs(lh - rh) < 2};
        
    }
public:
    bool isBalanced(TreeNode* root) {
        
        return !root || fun(root).second;
    }
};