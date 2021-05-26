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

//Time complexity - O(max(m,n))
//Space complexity - O(1), if we don't consider the output list, else O(max(m,n)),The length of the new list is at most max(m,n)+1.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) { //O(max(m,n)), Assume that m and n represents the length of l1 and l2 respectively
        if (!l1) return l2;
        if (!l2) return l1;
        int count_l1 = 0, count_l2 = 0;
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *head = NULL;
        ListNode *current;
        int carry = 0;
        while (temp1 || temp2)
        {
            int data;
            if (temp1 && temp2)  data = temp1->val + temp2->val + carry;
            else if (temp1 && !temp2)  data = temp1->val + carry;
            else data = temp2->val + carry;

            if (data <= 9)
            {
                carry = 0;
                if (!head)
                {
                    head = new ListNode(data);
                    current = head;
                }
                else
                {
                    current->next = new ListNode(data);
                    current = current->next;
                }
            }
            else
            {
                if (!head)
                {
                    head = new ListNode(data % 10);
                    current = head;
                    carry = data / 10;
                }
                else
                {
                    current->next = new ListNode(data % 10);
                    current = current->next;
                    carry = data / 10;
                }
            }
            if (temp1)   temp1 = temp1->next;
            if (temp2)   temp2 = temp2->next;
        }
        if (carry)
        {
            current->next = new ListNode(carry);
        }
        return head;
    }
};


//Time complexity - O(max(m,n))
//Space complexity - O(1), if we don't consider the output list, else O(max(m,n)),The length of the new list is at most max(m,n)+1.
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if (!l1) return l2;
        if (!l2) return l1;

        int carry = 0;

        ListNode *head = NULL, *temp1 = l1, *temp2 = l2;
        ListNode *current;
        while (temp1 && temp2)
        {
            int sum = temp1->val + temp2->val + carry;
            carry = sum / 10;
            sum %= 10;

            if (head == NULL)
            {
                head = new ListNode(sum);
                current = head;
            }

            else
            {
                current->next = new ListNode(sum);
                current = current->next;
            }

            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        while (temp1)
        {
            int sum = temp1->val + carry;
            carry = sum / 10;
            sum %= 10;
            current->next = new ListNode(sum);
            temp1 = temp1->next;
            current = current->next;
        }
        while (temp2)
        {
            int sum = temp2->val + carry;
            carry = sum / 10;
            sum %= 10;
            current->next = new ListNode(sum);
            temp2 = temp2->next;
            current = current->next;
        }
        if (carry)   current->next = new ListNode(carry);
        return head;
    }
};

//Using dummy node, above code becomes much cleaner
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