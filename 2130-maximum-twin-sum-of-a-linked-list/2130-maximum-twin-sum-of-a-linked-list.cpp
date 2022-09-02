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
    
    ListNode* reverse(ListNode *head, ListNode *stop = NULL) {
        
        if(!head || !head -> next) return head;
            
        ListNode *ptr = head,
                 *prv = NULL;
        
        while(ptr != stop) {
            ListNode *tmp = ptr -> next;
            ptr -> next = prv;
            prv = ptr;
            ptr = tmp;
            
        }
        
        return prv;
    }
    
    ListNode* middle(ListNode *head) {
        if(!head || !head -> next || !(head -> next -> next))
            return head;
        
        ListNode *fast = head,
                 *slow = head;
        
        while(fast -> next && fast -> next -> next)
            fast = fast -> next -> next,
            slow = slow -> next;
        
        return slow;
    }
    
    int pairSum(ListNode* head) {
        
        int ans = 0;
        ListNode *mptr = middle(head),
                 *fptr = mptr -> next,
                 *rptr = reverse(head, mptr -> next);
        
        
        while(fptr && mptr)
            ans = max(ans, fptr -> val + mptr -> val),
            fptr = fptr -> next, mptr = mptr -> next;
        
        
        return ans;
    }
};