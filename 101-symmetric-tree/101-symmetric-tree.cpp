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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if((!p && q) || (p && !q)) return false;
        return isSameTree(p->left, q->left) && p->val == q->val && isSameTree(p->right, q->right);
    }
    
    void invert(TreeNode *root) {
        if(!root) return;
        TreeNode *tmp = root -> left;
        root -> left = root -> right;
        root -> right = tmp;
        invert(root -> left);
        invert(root -> right);
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        invert(root -> left);
        return isSameTree(root -> left, root -> right);
    }
};