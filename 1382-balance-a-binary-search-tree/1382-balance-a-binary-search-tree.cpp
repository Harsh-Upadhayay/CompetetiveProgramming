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
    
    void inorder(TreeNode *root) {
        if(!root) return;
        inorder(root -> left);
        traversal.push_back(root -> val);
        inorder(root -> right);
    }
    
    TreeNode* construct(int l, int e) {
        
        // 1 2 3 4 5 
        
        if(l > e) return  NULL;
        
        int mid = (l + e) / 2;
        
        TreeNode *root = new TreeNode(traversal[mid], construct(l, mid - 1), construct(mid + 1, e));
        return root;
    }
    
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return construct(0, traversal.size() - 1);
        
    }
};