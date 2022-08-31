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
    
    vector<vector<int>> paths;
    vector<int> path;
    
    void hasPathSum(TreeNode* root, int targetSum, int cur_sum = 0) {
        
        if(!root) 
            return;
        
        cur_sum += root -> val;
        path.push_back(root -> val);
         
        if(!root -> right && !root -> left && cur_sum == targetSum)
            paths.push_back(path);
         
         hasPathSum(root -> left , targetSum, cur_sum);
         hasPathSum(root -> right, targetSum, cur_sum);
         
        cur_sum -= root -> val;
        path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        paths.clear();
        path.clear();
        hasPathSum(root, targetSum);
        return paths;
    }
};