
 
class Solution {
public:
ListNode *oddEvenList(ListNode *head)
{
    ListNode *ptr = head;
    ListNode *List = new ListNode(0);
    ListNode *tempList = List;

    if(ptr == NULL)
        return head;

    while (ptr->next != NULL)
    {
        int temp = ptr->next->val;
        ptr->next = ptr->next->next;
        tempList->next = new ListNode(temp);
        tempList = tempList->next;
        if(ptr->next  != NULL)
            ptr = ptr->next;
    }

    ptr->next = List->next;
    return head;
}

};