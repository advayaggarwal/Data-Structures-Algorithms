//Time complexuty - O(nlogn)
//Space complexity - O(logn), considering recursive call stack
class Solution {
public:
    ListNode* sortList(ListNode* head) {

        if (!head || !head->next)    return head;

        ListNode *slow = head, *fast = head->next;

        //Finding the middle
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        //Segregating both the halves
        ListNode *temp = slow->next;
        slow->next = NULL;

        ListNode *left_half = sortList(head);

        ListNode *right_half = sortList(temp);

        return merge(left_half, right_half);
    }

    ListNode* merge(ListNode *left_half, ListNode *right_half)
    {
        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;

        while (left_half && right_half)
        {
            if (left_half->val < right_half->val)
            {
                current->next = left_half;
                left_half = left_half->next;
            }
            else
            {
                current->next = right_half;
                right_half = right_half->next;
            }
            current = current->next;
        }

        if (left_half)   current->next = left_half;
        else current->next = right_half;

        return dummy->next;
    }

};



/**
 * Merge sort use bottom-up policy,
 * so Space Complexity is O(1)
 * Time Complexity is O(NlogN)
 * stable sort
*/
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !(head->next)) return head;

        //get the linked list's length
        ListNode* cur = head;
        int length = 0;
        while (cur) {
            length++;
            cur = cur->next;
        }

        ListNode dummy(0);
        dummy.next = head;
        ListNode *left, *right, *tail;
        for (int step = 1; step < length; step <<= 1) {
            cur = dummy.next;
            tail = &dummy;
            while (cur) {
                left = cur;
                right = split(left, step);
                cur = split(right, step);
                tail = merge(left, right, tail);
            }
        }
        return dummy.next;
    }
private:
    /**
     * Divide the linked list into two lists,
     * while the first list contains first n ndoes
     * return the second list's head
     */
    ListNode* split(ListNode *head, int n) {
        //if(!head) return NULL;
        for (int i = 1; head && i < n; i++) head = head->next;

        if (!head) return NULL;
        ListNode *second = head->next;
        head->next = NULL;
        return second;
    }
    /**
      * merge the two sorted linked list l1 and l2,
      * then append the merged sorted linked list to the node head
      * return the tail of the merged sorted linked list
     */
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head) {
        ListNode *cur = head;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
            else {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
        }
        cur->next = (l1 ? l1 : l2);
        while (cur->next) cur = cur->next;
        return cur;
    }
};