/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
// 2 3 n 
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        
        deque<Node*> dq;
        dq.push_back(root);
        dq.push_back(NULL);
        
        Node* prev = NULL;
        
        while(dq.size() > 1) {
        
            Node* curr  = dq.front(); dq.pop_front();
            if(prev) prev -> next = curr;
            prev = curr;
            
            if(!curr) {
                dq.push_back(NULL);
                continue;
            }
            if (curr -> left) dq.push_back(curr -> left);
            if (curr -> right) dq.push_back(curr -> right);
        }
        
        return root;
    }
};