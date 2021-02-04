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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)    return head;
        ListNode *temp;
        ListNode *p = head;
        head = head->next;
        ListNode *q;
        while (1)
        {
            if (p)    q = p->next;
            if (q)    temp = q->next;
            if (q)    q->next = p;
            if (!temp || !temp->next)
            {
                if (p)   p->next = temp;
                break;
            }
            if (p)    p->next = temp->next;
            p = temp;
        }
        return head;
    }
};