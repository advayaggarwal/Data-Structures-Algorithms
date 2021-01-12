/*
	AUTHOR:			ADVAY AGGARWAL
	INSTITUTION:	IIIT DHARWAD
*/
#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long
#define test_cases(x)	int x; cin>>x; while(x--)
#define vi vector<int>
#define setbits(x)      __builtin_popcountll(x)
#define endl "\n"

void starter()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}

class Node {
public:
	int data;
	Node* next;

	Node(int d) //Constructor
	{
		data = d;
		next = NULL;
	}
};

void print_ll(Node*head) //O(n) , visiting every node once
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

bool if_palindrome(Node *head)
{
	if (!head || !head->next)	return true; //if linked list is empty or contains only one node
	Node* head1 = NULL;
	//Step 1 - Break the linked list from the middle
	Node *slow = head, *fast = head;
	while (1) //take care in finding the middle
	{
		if (fast && fast->next)	fast = fast->next->next; //before doing fast->next or fast->next->next check if fast and fast->next are !NULL,
		// otherwise it will give runtime error: member access within null pointer of type 'Node'
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
	Node *current = head1, *prev = NULL;
	while (current)
	{
		Node *next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head1 = prev;

	//Step 3 - Compare both the linked lists
	while (head && head1)
	{
		if (head->data != head1->data) break;
		head = head->next;
		head1 = head1->next;
	}

	if (!head && !head1) // Both points to null, that is while loop doesn't encounter break statement
	{
		return true;
	}
	else return false;
}

int main()
{
	starter();
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(2);
	head->next->next->next->next = new Node(1);
	head->next->next->next->next->next = NULL;
	//print_ll(head);
	if (if_palindrome(head) == true)
	{
		cout << "Yes it's a palindrome";
	}
	else cout << "No it's not a palindrome";
	return 0;
}