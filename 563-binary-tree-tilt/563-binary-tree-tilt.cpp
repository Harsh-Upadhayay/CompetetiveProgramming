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
    int modifyTree(TreeNode* root, int cur_sum = 0) {
        
        if(!root) return 0;
        
        int lsum = modifyTree(root->left),
            rsum = modifyTree(root->right),
            tsum = lsum + root -> val + rsum;
        
        root -> val = abs(rsum - lsum);
        
        return tsum;
    }
    int sumTree(TreeNode* root) {
        
        if (!root) return 0;
        
        int l = sumTree(root->left),
            r = sumTree(root->right);
        
        return l + r + root -> val;
    }
    
    void inorder(TreeNode* root) {
        
        if(!root) return;
        
        inorder(root -> left);
        cout << root -> val << " ";
        inorder(root -> right);
        
    }
    
public:
    int findTilt(TreeNode* root) {
        
        modifyTree(root);
        // inorder(root); cout << endl;
        return sumTree(root);
        
    }
};