//Iterative
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *current = head;
        while (current && current->next)
        {
            if (current->val == current->next->val)
            {
                ListNode *temp = current->next;
                current->next = current->next->next;
                delete(temp);
            }
            else current = current->next;
        }
        return head;
    }
};

//Recursive
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        if (!head or !head->next)    return head;

        ListNode *subans = deleteDuplicates(head->next);

        if (subans && head->val == subans->val)    return subans;

        head->next = subans;

        return head;
    }
};