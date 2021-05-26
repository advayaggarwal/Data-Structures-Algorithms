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

//Time complexity - O(n)
//Space complexity - O(n), we made a completely new list
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if (!head || !head->next || !head->next->next)    return head;

        ListNode *reordered_head = new ListNode(head->val);

        ListNode *p = reordered_head;

        ListNode *temp = head->next->next;

        while (temp)
        {
            p->next = new ListNode(temp->val);
            p = p->next;
            if (temp->next) temp = temp->next->next;
            else break;

        }

        temp = head->next;
        while (temp)
        {
            p->next = new ListNode(temp->val);
            p = p->next;
            if (temp->next) temp = temp->next->next;
            else break;

        }

        return reordered_head;

    }
};


//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if (!head || !head->next || !head->next->next)    return head;

        ListNode *odd = head;
        ListNode*evenHead = head->next;
        ListNode *even = head->next;
        while (even && even->next)
        {

            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;

    }
};