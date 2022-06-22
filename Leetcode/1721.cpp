//Two pass
//Time complexity - O(n)
//Space complexity - O(1)
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

//One pass
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k)
    {
        ListNode *n1 = NULL, *n2 = NULL;
        for (ListNode *temp = head; temp != NULL; temp = temp->next)
        {
            n2 = n2 ? n2->next : NULL;
            if (--k == 0)
            {
                n1 = temp;
                n2 = head;
            }
        }

        swap(n1->val, n2->val);
        return head;
    }
};