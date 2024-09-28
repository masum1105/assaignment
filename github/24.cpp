
class Solution {
public:
ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while (curr != nullptr) {
            next = curr->next; 
            curr->next = prev; 
            prev = curr;       
            curr = next;      
        }
        return prev;
    }

   
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* result = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;
            
            
            int sum = val1 + val2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            
            
            ListNode* newNode = new ListNode(digit);
            
           
            if (result == nullptr) {
                result = newNode; 
            } else {
                tail->next = newNode; 
            }
            tail = newNode;
            
           
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }
        
     
        return result;
    }
};