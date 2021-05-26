/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 4 pass solution
//Time complexity - O(n+m)
//Space complexity - O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = 0, n = 0;
        ListNode *temp = headA;
        while (temp)
        {
            m++;
            temp = temp->next;
        }

        temp = headB;
        while (temp)
        {
            n++;
            temp = temp->next;
        }

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        if (m > n)
        {
            int count = m - n;
            while (count--)
            {
                temp1 = temp1->next;
            }
        }

        else
        {
            int count = n - m;
            while (count--)  temp2 = temp2->next;
        }


        while (temp1 != temp2)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }


        return temp1 == temp2 ? temp1 : NULL;

    }
};


// 1 pass solution
//Time complexity - O(n+m)
//Space complexity - O(1)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA, *temp2 = headB;

        while (temp1 != temp2)
        {
            //for the end of the 1st iteration, we just reset the pointer to the head of another linked list
            temp1 = temp1 == NULL ? headB : temp1->next;
            temp2 = temp2 == NULL ? headA : temp2->next;
        }

        return temp1;
    }
};