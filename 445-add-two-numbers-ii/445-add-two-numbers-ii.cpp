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
    ListNode* add(ListNode* l1, ListNode* l2) {
        
        if(!l1 || !l2) return l1 ? l1 : l2;
        
        
        ListNode *sum_head = new ListNode(l1-> val + l2 -> val);
        ListNode *ptr = sum_head;
        
        int carry = (ptr -> val) / 10;
        ptr -> val %= 10;
        l1 = l1 -> next;
        l2 = l2 -> next;
        
        while(l1 && l2) {
            
            ptr = ptr = ptr -> next = new ListNode(l1 -> val + l2 -> val + carry);
            carry = (ptr -> val) / 10;
            ptr -> val %= 10;
            l1 = l1 -> next;
            l2 = l2 -> next; 
        }
        
        while(l1)  {
    
            ptr = ptr -> next = new ListNode(l1 -> val + carry);  
            carry = (ptr -> val) / 10;
            ptr -> val %= 10;
            l1 = l1 -> next;     
        }
        
        while(l2) {
    
            ptr = ptr -> next = new ListNode(l2 -> val + carry);
            carry = (ptr -> val) / 10;
            ptr -> val %= 10;
            l2 = l2 -> next;
        }
        
        if(carry) 
            ptr -> next = new ListNode(carry);
        
        
        return sum_head;
    }
    
    ListNode *reverse(ListNode *ptr) {
        
        if(!ptr || !ptr -> next) return ptr;
        
        ListNode *prev = NULL;
        
        while(ptr) {
            
            ListNode *tmp = ptr -> next;
            ptr -> next = prev;
            prev = ptr;
            ptr = tmp;
        }
        
        return prev;       
    }
    
    void print(ListNode *h) {
        while(h) {
            cout << h -> val << " ";
            h = h -> next;
        }
        cout << "\n";
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // print(reverse(l1));
        // print(reverse(l2));
        
        return reverse(add(reverse(l1), reverse(l2)));
        
    }
};