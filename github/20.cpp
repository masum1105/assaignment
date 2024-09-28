
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        while (temp != NULL) {
            ListNode* st = temp;
            while (temp->next != NULL && temp->next->val == temp->val) {
                temp = temp->next;
            }
            if (prev == NULL) {
                if (st == temp) {
                    prev = st;
                } else {
                    head = temp->next;
                }
            } else if (st == temp) {
                prev = st;
               
            } else {
                prev->next = temp->next;
            }
            temp = temp->next;
        }
        return head;
    }
};