//Time complexity - O(n) One pass solution, without computing length
//Space complexity - O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)   return head;
        ListNode *slow = head, *fast = head;
        for (int i = 0; i < n; i++)
        {
            if (fast)    fast = fast->next;
        }

        if (!fast)
        {
            head = head->next;
            delete(slow);
            return head;
        }

        while (1)
        {
            if (fast)    fast = fast->next;
            if (!fast) break;
            if (slow)    slow = slow->next;
        }

        ListNode *temp = slow->next;

        if (temp)  slow->next = temp->next;
        delete(temp);
        return head;
    }
};



//First we will add an auxiliary "dummy" node, which points to the list head.
//The "dummy" node is used to simplify some corner cases such as a list with only one node, or removing the head of the list.
//Though concept is completely same as above code

//Time complexity - O(n) One pass solution, without computing length
//Space complexity - O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)   return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *slow = dummy, *fast = dummy;
        for (int i = 1; i <= n; i++)   fast = fast->next;

        while (fast->next) //fast will point to the last node of linked list
        {
            fast = fast->next;
            slow = slow->next;
        }
        //Now slow is pointing to one node before the Nth node from the end, so we can simply delete it
        ListNode *temp = slow->next;
        slow->next = slow->next->next;

        delete(temp);

        return dummy->next;
    }
};