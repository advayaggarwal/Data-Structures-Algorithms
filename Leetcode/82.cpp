//Iterative
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *temp = dummy;

        while (temp && temp->next)
        {
            bool flag = false;
            ListNode *current = temp->next;
            while (current && current->next && current->val == current->next->val)
            {
                current = current->next;
                flag = true;
            }

            if (flag)
            {
                temp->next = current->next;
            }
            else
            {
                temp->next = current;
                temp = temp->next;
            }
        }

        return dummy->next;
    }
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (!head)   return NULL;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *temp = dummy;
        ListNode *curr = head;
        while (curr)
        {
            while (curr->next && curr->val == curr->next->val)   curr = curr->next;

            if (temp->next == curr)  temp = temp->next;
            else    temp->next = curr->next;

            curr = curr->next;
        }

        return dummy->next;
    }
};

//Recursive
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (!head or !head->next)   return head;

        int val = head->val;
        ListNode *p = head->next;

        if (p->val != val)
        {
            head->next = deleteDuplicates(p);
            return head;
        }

        else
        {
            while (p && p->val == val)   p = p->next;

            return deleteDuplicates(p);
        }
    }
};