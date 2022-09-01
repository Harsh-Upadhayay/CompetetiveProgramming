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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head -> next) return head;
        
        ListNode *prev = NULL,
                 *ptr  = head;
        while(ptr) {
            ListNode *tmp = ptr -> next;
            ptr -> next = prev;
            prev = ptr;
            ptr = tmp;
        }
        return prev;
    }
};