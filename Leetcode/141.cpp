/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode *slow = head, *fast = head;

        while (slow && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)  return true;
        }
        return false;
    }
};



//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> hash;
        ListNode*p = head;
        while (p)
        {
            if (hash.find(p) != hash.end())    return true;
            else hash.insert(p);
            p = p->next;
        }
        return false;
    }
};