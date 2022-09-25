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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> view;
        if(!root) return view;
        
        TreeNode *prev = NULL;
        deque<TreeNode*> q;
        q.push_back(root);
        q.push_back(NULL);
        int itr = 10;
        while(q.size() > 1) {
        
            TreeNode* curr = q.front(); q.pop_front();
            
            if(!curr) {
                q.push_back(NULL);
                view.push_back(prev -> val);
                continue;
            }
            
            if(curr -> left) q.push_back(curr -> left);
            if(curr -> right) q.push_back(curr -> right);
            
            prev = curr;                
        }
        view.push_back(prev -> val);
        return view;        
    }
};