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
    
    vector<TreeNode*> nodes;
    void nodes_at_x(TreeNode* root, int dpth, int x) {
        
        if(!root) return;
        nodes_at_x(root -> left, dpth + 1, x);
        nodes_at_x(root -> right, dpth + 1, x);
        if(dpth == x)
            nodes.push_back(root);        
    }
    
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1) return new TreeNode(val, root, NULL);
        
        nodes.clear();
        nodes_at_x(root, 1, depth - 1);
        
        for(TreeNode* node : nodes) {
            
            TreeNode  *nl = new TreeNode(val, node -> left, NULL),
                      *nr = new TreeNode(val, NULL, node -> right);
            
            node -> left = nl,
            node -> right = nr;
        }
        
        return root;        
    }
};