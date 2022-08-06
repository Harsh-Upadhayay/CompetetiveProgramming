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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(NULL == head || NULL == head->next)
            return NULL;
        
        ListNode *ahead = head, *curr = head;
        for(int i = 0; i <= n; i++) {
            if(!ahead) 
                return head->next;
            
            ahead = ahead -> next;
        }
        
        while(ahead) ahead = ahead -> next, curr = curr -> next;
        curr -> next = curr -> next -> next;
        return head;
    }
};