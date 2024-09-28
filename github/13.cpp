

class Solution {
public:
// solution 1:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) {
            return nullptr;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;

        while (first->next) {
            if (first->next->val == val) {
                ListNode* toDelete = first->next;
                first->next = toDelete->next;
                delete toDelete;
            } else {
              first = first->next;
            }        
        }

        head = dummy->next;
        delete dummy;

        return head;



    }
};