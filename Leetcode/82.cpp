//Iterative
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *temp = dummy;

        while (temp && temp->next)
        {
            bool flag = false;
            ListNode *current = temp->next;
            while (current && current->next && current->val == current->next->val)
            {
                current = current->next;
                flag = true;
            }

            if (flag)
            {
                temp->next = current->next;
            }
            else
            {
                temp->next = current;
                temp = temp->next;
            }
        }

        return dummy->next;
    }
};