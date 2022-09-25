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
    int num, sum;
    void preorder(TreeNode* root) {
        if(!root) return;
        num = num * 10 + root -> val;
        if(!root -> right && !root -> left)
            sum += num;
        preorder(root -> left);
        preorder(root -> right);
        num /= 10;        
    }
    
public:
    int sumNumbers(TreeNode* root) {
        num = 0, sum = 0;
        preorder(root);
        return sum;
    }
};