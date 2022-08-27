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
    int modifyTree(TreeNode* root, int &cur_sum) {
        
        if(!root) return 0;
        
        int lsum = modifyTree(root->left, cur_sum),
            rsum = modifyTree(root->right, cur_sum),
            tsum = lsum + root -> val + rsum;
        
        cur_sum += abs(rsum - lsum);
        
        return tsum;
    }
   
    
public:
    int findTilt(TreeNode* root) {
        
        int tilt = 0;
        modifyTree(root, tilt);
        return (tilt);
        
    }
};