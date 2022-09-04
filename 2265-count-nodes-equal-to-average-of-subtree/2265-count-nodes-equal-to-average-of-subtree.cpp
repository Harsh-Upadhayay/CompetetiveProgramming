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
    
    int sum, count;
    pair<int, int> inorder(TreeNode *root) {
        if(!root) return {0, 0};
        
        pair<int, int> l = inorder(root -> left),
                       r = inorder(root -> right);
        
        int s = l.first + r.first + root -> val,
            n = l.second + r.second + 1;
        
        
        if(root -> val == s / n) {
            cout << root -> val << " ";
            count++;
        }
        
        return {s, n};
    }
    
public:
    int averageOfSubtree(TreeNode* root) {
    
        sum = 0, count = 0;
        inorder(root);
        return count;
        
    }
};