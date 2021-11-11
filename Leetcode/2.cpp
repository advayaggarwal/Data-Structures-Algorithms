//Time complexity - O(max(m,n))
//Space complexity - O(1), if we don't consider the output list, else O(max(m,n)),The length of the new list is at most max(m,n)+1.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if (!l1) return l2;
        if (!l2) return l1;

        int carry = 0;
        ListNode *dummy = new ListNode(0);
        ListNode  *temp1 = l1, *temp2 = l2;
        ListNode *current = dummy;

        while (temp1 || temp2)
        {
            int x = temp1 ? temp1->val : 0;
            int y = temp2 ? temp2->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            sum %= 10;
            current->next = new ListNode(sum);
            current = current->next;


            if (temp1)  temp1 = temp1->next;
            if (temp2)  temp2 = temp2->next;
        }
        if (carry)   current->next = new ListNode(carry);
        return dummy->next;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        int carry = 0;
        ListNode *dummy = new ListNode(0);
        ListNode *head = dummy;

        while (l1 or l2 or carry)
        {
            int sum = carry;

            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            ListNode *temp = new ListNode(sum % 10);
            carry = sum / 10;

            head->next = temp;
            head = head->next;
        }

        return dummy->next;
    }
};