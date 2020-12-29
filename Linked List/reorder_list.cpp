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

Node* cut_in_half(Node* head)	//Tortoise & Hare Algo, Time complexity = O(n), Space complexity = O(1)
{
	Node* slow = head;
	Node* fast = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	Node* head2 = slow->next;
	slow->next = NULL;
	return head2;
}

void reverse(Node* &head)
{
	Node *current = head, *prev = NULL, *next;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

void merge(Node* head1, Node* head2)
{
	while (head1 != NULL && head2 != NULL)
	{
		Node* temp1 = head1->next;
		Node* temp2 = head2->next;
		head1->next = head2;
		head1 = temp1;
		head2->next = head1;
		head2 = temp2;
	}
}

/*
	Steps to reorder the list
	1. Cut the given list in 2 halves from mid
	2. Reverse the 2nd half
	3. Then merge the both halves as shown: -

						1->2->3->4  &&  6->5 to 1->6->2->5->3->4
*/
void reorder(Node* &head)
{
	if (!(head) || !(head->next) || !(head->next->next))	return; //if list is empty or list contains only 1 or 2 elements, then we've nothing to do
	Node* head2 = cut_in_half(head);
	reverse(head2);
	merge(head, head2);
}

void print_ll(Node*head) //O(n) , visiting every node once
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
}

int main()
{
	starter();
	Node* head = NULL;
	head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = new Node(6);
	reorder(head);
	print_ll(head);
	return 0;
}