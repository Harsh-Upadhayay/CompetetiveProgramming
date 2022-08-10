/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(!cloned)
            return NULL;
        TreeNode *right = getTargetCopy(original, cloned->right, target); 
        TreeNode *left = getTargetCopy(original, cloned->left, target);
        if(target->val == cloned->val)
            return cloned;
        else if(right) return right;
        else if(left)  return left;
        else           return NULL;
    }
};