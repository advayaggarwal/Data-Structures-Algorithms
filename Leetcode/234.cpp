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


//Time complexity - O(n)
//Space complexity - O(1)
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
			if (!fast->next) //length of linked list is odd, therefore discard the middle one
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
			if (head->val != head1->val) return false;
			head = head->next;
			head1 = head1->next;
		}

		return true;
	}
};


//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next)   return true;

		ListNode *slow = head, *fast = head->next; //if we initialise fast as head->next then it will give 1st middle in case of even length, in odd length list both will be same

		//Finding middle of the linked list
		while (fast && fast->next)
		{
			fast = fast->next->next;
			slow = slow->next;
		}

		//Reverse the second half
		slow->next = reverse(slow->next);

		slow = slow->next;
		fast = head;
		//Comparing both the halves
		while (slow)
		{
			if (fast->val != slow->val)  return false;
			fast = fast->next;
			slow = slow->next;
		}
		return true;
	}


	ListNode* reverse(ListNode *head)
	{
		ListNode *prev = NULL;

		while (head)
		{
			ListNode *nextNode = head->next;
			head->next = prev;
			prev = head;
			head = nextNode;
		}

		return prev;
	}
};



//Recursive

/* There are 2 disadvantages however:
1. It's using O(n) memory due to the recursive calls' stack.
2. The element by element comparison continues past the middle of the list, which is wasteful.

Explanation
..........................................................................................
Example :
1-> 2-> 3-> 4-> 2-> 1

temp points 1 initially.
Make recursive calls until you reach the last element - 1.
On returning from each recurssion, check if it is equal to temp values.
temp values are updated to on each recurssion.
So first check is temp 1 -  end 1
Second temp 2 - second last 2 ...and so on. */

class Solution {
public:
	ListNode* temp;
	bool isPalindrome(ListNode* head) {
		temp = head;
		return check(head);
	}

	bool check(ListNode* p) {
		if (NULL == p) return true;
		bool isPal = check(p->next) & (temp->val == p->val);
		temp = temp->next;
		return isPal;
	}
};