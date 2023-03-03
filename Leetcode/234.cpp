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

//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
	ListNode* temp;
	bool isPalindrome(ListNode* head) {
		temp = head;
		return check(head);
	}

	bool check(ListNode* p) {
		if (p == NULL) return true;
		bool isPal = check(p->next) & (temp->val == p->val);
		temp = temp->next;
		return isPal;
	}
};