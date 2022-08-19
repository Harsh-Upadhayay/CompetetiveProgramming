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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        map<int, pair<TreeNode*, bool>> nodes;
        for(auto desc : descriptions) {
            
            TreeNode *child = new TreeNode(desc[1]),
                     *parent = new TreeNode(desc[0]);
            
            auto c = nodes.find(desc[1]),
                 p = nodes.find(desc[0]);
            
            if(nodes.end() != c)
                child = c->second.first;
            else
                nodes.insert({child->val, {child, true}});
            
            if(nodes.end() != p)
                parent = p->second.first;
            else
                nodes.insert({parent->val, {parent, false}});
            
            if(desc[2])
                parent->left = child;
            else
                parent->right = child;
            nodes[child->val].second = true;
        }
        TreeNode* root = NULL;
        for(auto x : nodes)
            if(!x.second.second)
                root = x.second.first;
        return root;
            
    }
};