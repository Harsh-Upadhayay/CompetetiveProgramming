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
public:
    bool hasPathSum(TreeNode* root, int targetSum, int cur_sum = 0) {
        
        if(!root) 
            return false;
        
        cur_sum += root -> val;
        
               
        bool chk =  (
                    (!root -> right && !root -> left) ? 
                     (cur_sum == targetSum) :
                     (hasPathSum(root -> left , targetSum, cur_sum) || 
                      hasPathSum(root -> right, targetSum,cur_sum))
                    );
        
        cur_sum -= root -> val;
        return chk;
    }
};