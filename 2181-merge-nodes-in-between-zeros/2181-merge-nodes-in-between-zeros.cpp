/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        if(!head || !head -> next) return NULL;
        ListNode *nhead = new ListNode(0);
        
        head = head -> next;

        while(head && head -> next && head -> next -> val != 0)
            nhead -> val += head -> val,
            head = head -> next;
        
        nhead -> val += head -> val;
        
        nhead -> next = mergeNodes(head -> next);
            
        return nhead;
    }
};