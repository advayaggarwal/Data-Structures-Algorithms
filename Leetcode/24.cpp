//Iterative
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (!head or !head->next)    return head;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *prev = dummy, *current = head;

        while (current && current->next)
        {
            prev->next = current->next;
            current->next = current->next->next;
            prev->next->next = current;

            current = current->next;
            prev = prev->next->next;
        }

        return dummy->next;
    }
};

//Recursive
//Time complexity - O(n)
//Space complexity - O(n), recursive stack space
class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (!head or !head->next)    return head;

        ListNode *nHead = head->next;
        head->next = swapPairs(head->next->next);

        nHead->next = head;

        return nHead;
    }
};