//Recursive
//Time complexity - O(n)
//Space complexity - O(n/k), used in recursion stack
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (!head or !head->next or k == 1)    return head;

        int count = 0;
        ListNode *ptr = head;

        while (count < k && ptr)
        {
            ptr = ptr->next;
            count++;
        }

        if (count == k)
        {
            ListNode *rev_head = reverse(head, k);
            head->next = reverseKGroup(ptr, k);

            return rev_head;
        }

        return head; //list is of size less than k, therefore simply return head
    }

    ListNode* reverse(ListNode *head, int k)
    {
        if (!head or !head->next)    return head;

        ListNode *prev = NULL, *current = head;
        int count = 0;
        while (current && count < k)
        {
            ListNode *next = current->next;
            count++;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};

//Iterative
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (!head or !head->next or k == 1)    return head;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *beforeStart = dummy, *end = head;
        int count = 0;

        while (end)
        {
            count++;
            if (count % k == 0) //reverse
            {
                ListNode *start = beforeStart->next;
                ListNode *temp = end->next;
                reverse(start, k);
                beforeStart->next = end;
                start->next = temp;
                beforeStart = start;
                end = start->next;
            }

            else    end = end->next;
        }

        return dummy->next;
    }

    void reverse(ListNode *start, int k)
    {
        ListNode *prev = NULL, *current = start;
        int count = 0;

        while (current && count < k)
        {
            ListNode *next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
    }
};