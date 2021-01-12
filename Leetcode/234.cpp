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
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next)   return true;
		ListNode* head1 = NULL;
		//Step 1 - Break the linked list from the middle
		ListNode *slow = head, *fast = head;
		while (1) //take care in finding the middle
		{
			if (fast && fast->next )fast = fast->next->next;
			/*
			We are moving the slow pointer after checking the if conditions as if fast already reached NULL
			then we have to set slow->next=NULL, as once we move forward we can't revert back
			*/
			if (!fast) //length of linked list is even
			{
				head1 = slow->next;
				break;
			}
			//first check is fast is not null, that is if fast is null then fast->next will throw null point exception
			if (fast && !fast->next) //length of linked list is odd, therefore discard the middle one
			{
				head1 = slow->next->next;
				break;
			}
			slow = slow->next;
		}
		slow->next = NULL;

		//Step 2 - Reverse the second linked list
		ListNode *current = head1, *prev = NULL;
		while (current)
		{
			ListNode *next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head1 = prev;

		//Step 3 - Compare both the linked lists
		while (head && head1)
		{
			if (head->val != head1->val) break;
			head = head->next;
			head1 = head1->next;
		}

		if (!head && !head1) // Both points to null, that is while loop doesn't encounter break statement
		{
			return true;
		}
		else return false;
	}
};