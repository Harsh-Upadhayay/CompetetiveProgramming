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
    vector<int> traversal;
    void traverse(TreeNode* root) {
        if(!root)
            return;
        traverse(root->left);
        traversal.push_back(root->val);
        traverse(root->right);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        traversal.clear();
        traverse(root);
        return traversal;
    }
};