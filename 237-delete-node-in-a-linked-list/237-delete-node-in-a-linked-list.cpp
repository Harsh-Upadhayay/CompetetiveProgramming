/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *prv = node,
                 *slt = NULL;
        node = node -> next;
        while(node) {
            prv -> val = node -> val;
            if(node -> next == NULL) slt = prv;
            prv = node;
            node = node -> next;
        }
        slt -> next = NULL;
    }
};