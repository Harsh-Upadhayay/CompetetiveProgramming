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
    void flatten(TreeNode* root) {
        stack<TreeNode*> waiting;
        
        TreeNode* curr = root, *prev = NULL;
        while(curr) {
            if(!(curr->right) && !(curr->left)) {
                if(!waiting.size())
                    return;
                curr -> right = waiting.top();
                waiting.pop();
            }
            else if(curr -> left) {
                if(curr -> right)
                    waiting.push(curr->right);
                curr -> right = curr->left;
            }
            curr -> left = NULL;
            prev = curr;
            curr = curr -> right;
        }
    }
};