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

//Tortoise and Hare Algorithm OR Floyd's Cycle Detection Algorithm
Node* detect_cycle(Node *head) //O(N+K) = O(n) where N is non-cyclic part and K is cyclic part
// returns the node where the slow and fast pointers are meeting
{
	Node *slow = head, *fast = head;
	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)	return fast;
	}
	return NULL; //there is no cycle
}

Node* remove_loop(Node *fast, Node *head)
{
	if (!fast)	return NULL;
	Node *slow = head;
	/* No need of slow pointer actually we can also work upon head pointer also because it is pass by value,
	i.e. we're actually working on the copy of head */
	if (fast == head) //i.e. loop is from the starting (CORNER CASE)
	{
		while (fast->next != head)
		{
			fast = fast->next;
		}
		fast->next = NULL;
		return slow;
	}
	else
	{
		while (slow->next != fast->next)
		{
			slow = slow->next;
			fast = fast->next;
		}
		fast->next = NULL;
		return slow->next; //slow to next is pointing to the start of the loop
	}
}

int main()
{
	starter();
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = head->next;
	/*
		1 -> 2 <-> 3
	*/
	if (detect_cycle(head))
	{
		Node *start_of_loop = remove_loop(detect_cycle(head), head);
		cout << "Loop is starting at " << start_of_loop->data << endl;
		cout << "Yeah, we removed the loop successfully!! ;) " << endl;
		print_ll(head);
	}
	else
	{
		cout << "Fortunately there was no loop :)" << endl;
		print_ll(head);
	}
	return 0;
}