//Hare and tortoise method
//Time complexity - O(n)
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (!head or !head->next)    return head;

        ListNode *slow = head, *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};