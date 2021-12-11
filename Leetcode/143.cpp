//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    void reorderList(ListNode* head) {
        if ((!head) || (!head->next) || (!head->next->next)) return;
        ListNode* slow = head;
        ListNode* fast = head;
        //finding the middle of ll
        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        //splitting the ll from middle
        ListNode* head2 = slow->next;
        slow->next = NULL;
        //reversing the 2nd ll
        ListNode* current = head2;
        ListNode* prev = NULL;
        ListNode* next;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head2 = prev;
        while (head != NULL && head2 != NULL)
        {
            ListNode* temp1 = head->next;
            ListNode* temp2 = head2->next;
            head->next = head2;
            head = temp1;
            head2->next = head;
            head2 = temp2;
        }
    }
};