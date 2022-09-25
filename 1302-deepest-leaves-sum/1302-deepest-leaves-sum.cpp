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
    int sum;
    int ht;
    
    int height(TreeNode* root) {
        if(!root) return 0;
        return max(height(root ->left), height(root -> right)) + 1;
    }
    
    void perform_sum(TreeNode* root, int depth = 1) {
        if(!root) return;
        if(depth == ht && !root -> right && !root -> left)
            sum += root -> val;
        perform_sum(root -> left, depth + 1);
        perform_sum(root -> right, depth + 1);
    }
    
    
public:
    int deepestLeavesSum(TreeNode* root) {
        sum = 0,
        ht = height(root);
        perform_sum(root);
        return sum;
    }
};