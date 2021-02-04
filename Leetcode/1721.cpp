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
    ListNode* swapNodes(ListNode* head, int k) {
        if (!head || !head->next)    return head;
        ListNode *temp = head;
        k--;
        while (k--)
        {
            temp = temp->next;
        }
        ListNode *slow = head, *fast = temp;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        swap(temp->val, slow->val);
        return head;
    }
};