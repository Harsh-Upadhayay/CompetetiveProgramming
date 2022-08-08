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
    long long prev;
public:
    Solution() {
        prev = -1000000000000;
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bool flag = true;
        flag &= isValidBST(root->left);
        flag &= (root->val > prev);
        prev = root->val;
        flag &= isValidBST(root->right);
        return flag;    
    }
};