//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if (left >= right)   return head;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *temp = dummy;
        int count = 0;
        while (temp && count < left - 1)
        {
            temp = temp->next;
            count++;
        }

        ListNode *prev = NULL, *curr = temp->next;
        while (curr && count < right)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        temp->next->next = curr;
        temp->next = prev;

        return dummy->next;
    }
};