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