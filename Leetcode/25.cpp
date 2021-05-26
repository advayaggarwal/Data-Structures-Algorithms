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
    ListNode* reverseKGroup(ListNode* head, int k) {

        if (head == NULL)    return NULL;

        ListNode *t = head;
        int count  = 0;
        while (t && count != k) { // find the k+1 node
            t = t->next;
            count++;
        }
        if (count == k) {
            ListNode *prev = NULL, *current = head, *temp;
            while (current && count > 0)
            {
                temp = current->next;
                current->next = prev;
                prev = current;
                current = temp;
                count--;
            }

            if (temp)    head->next = reverseKGroup(temp, k);

            return prev;
        }
        return head;
    }
};