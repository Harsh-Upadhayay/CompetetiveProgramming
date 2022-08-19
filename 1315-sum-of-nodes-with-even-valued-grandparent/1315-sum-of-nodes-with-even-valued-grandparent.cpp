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
    #define nll(x) x->left->left
    #define nrr(x) x->right->right
    #define nlr(x) x->left->right
    #define nrl(x) x->right->left
    void inorder(TreeNode* root, int &sum) {
        if(!root) return;
        inorder(root->left, sum);
        if(!(root->val % 2) && root->left) 
            sum += (nll(root) ? nll(root)->val : 0) + 
                +  (nlr(root) ? nlr(root)->val : 0) ;
        if(!(root->val % 2) && root->right)
            sum += (nrr(root) ? nrr(root)->val : 0) 
                +  (nrl(root) ? nrl(root)->val : 0) ;
        inorder(root->right, sum);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        inorder(root, sum);
        return sum;
    }
};