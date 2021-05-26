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

//Iterative
//Time complexity - O(n+m)
//Space complexity - O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode dummy(-1); //dummy node
        ListNode *temp = &dummy;

        while (l1 && l2)
        {
            if (l1->val <= l2->val)
            {
                temp->next = l1;
                l1 = l1->next;
            }
            else
            {
                temp->next = l2;
                l2 = l2->next;
            }
            temp = temp->next;
        }

        temp->next = l1 ? l1 : l2; //i.e. if one list gets exhausted then simply connect temp to the another list

        return dummy.next;
    }
};


//Recursive
//Time complexity - O(n+m)
//Space complexity - O(n+m) considering stack space for recursive calls
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }

        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};