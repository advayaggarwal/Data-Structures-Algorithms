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

Node* detect_cycle(Node *head) //O(N+K) = O(n) where N is non-cyclic part and K is cyclic part
// returns the node where the slow and fast pointers are meeting
{
	Node *slow = head, *fast = head;
	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)	return slow;
	}
	return NULL; //there is no cycle
}

Node* start_of_loop(Node *p, Node* head)
{
	if (!p)	return NULL;
	Node *q = head;
	while (p != q)
	{
		p = p->next;
		q = q->next;
	}
	return p;
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
	Node *start = start_of_loop(detect_cycle(head), head);
	if (start)	cout << start->data;
	return 0;
}