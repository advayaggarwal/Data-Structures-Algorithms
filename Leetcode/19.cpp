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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)   return head;
        ListNode *slow = head, *fast = head;
        for (int i = 0; i < n; i++)
        {
            if (fast)    fast = fast->next;
        }

        if (!fast)
        {
            head = head->next;
            delete(slow);
            return head;
        }

        while (1)
        {
            if (fast)    fast = fast->next;
            if (!fast) break;
            if (slow)    slow = slow->next;
        }

        ListNode *temp = slow->next;

        if (temp)  slow->next = temp->next;
        delete(temp);
        return head;
    }
};