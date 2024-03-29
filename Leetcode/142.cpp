//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        ListNode *slow = head, *fast = head;

        bool is_cycle = false;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                is_cycle = true;
                break;
            }
        }

        if (!is_cycle)  return NULL;

        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;

    }
};