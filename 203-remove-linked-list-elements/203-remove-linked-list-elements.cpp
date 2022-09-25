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
    ListNode* removeElements(ListNode* head, int val) {
        while(head && head -> val == val) head = head -> next;
        
        ListNode *ptr = head, 
                 *prv = NULL;
            
        
        while(ptr) {
            
            while(ptr && ptr -> val == val)
                prv -> next = ptr -> next,
                ptr = ptr -> next;
            
            prv = ptr;
            if(ptr) ptr = ptr -> next;
        }
        
        return head;
    }
};