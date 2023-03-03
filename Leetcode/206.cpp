
//Iterative

//Time complexity - O(n)
//Space complexity - O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *current = head;

        while (current)
        {
            ListNode *nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        return prev;

    }
};



//Recursive
//Time complexity - O(n)
//Space complexity - O(n), considering stack space for recursive calls

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) return head;
        helper(head, head);
        return head;
    }

    void helper(ListNode *p, ListNode *&head)
    {

        if (p->next == NULL)
        {
            head = p;
            return;
        }

        helper(p->next, head);

        p->next->next = p;
        p->next = NULL;
    }
};


//More elegant solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if (head == NULL || head->next == NULL)  return head;
        ListNode *shead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return shead;
    }
};