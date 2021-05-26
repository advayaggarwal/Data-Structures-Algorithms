/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//Time complexity - O(1)
//Space complexity - O(1)

class Solution {
public:
	void deleteNode(ListNode* node) {
		node->val = node->next->val;
		ListNode *temp = node->next;
		node->next = node->next->next;
		delete(temp);
	}
};