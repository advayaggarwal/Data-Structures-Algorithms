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

Node* merge_two_sorted_lists(Node* head1, Node* head2)
{
	if (!head1)	return head2;
	if (!head2)	return head1;
	Node* temp;
	if (head1->data <= head2->data)
	{
		temp = head1;
		head1 = head1->next;
	}
	else
	{
		temp = head2;
		head2 = head2->next;
	}
	Node* head = temp;
	while (head1 && head2)
	{
		if (head1->data <= head2->data)
		{
			temp->next = head1;
			head1 = head1->next;
			temp = temp->next;
		}
		else
		{
			temp->next = head2;
			head2 = head2->next;
			temp = temp->next;
		}
	}
	if (!head1)	temp->next = head2; //list1 is traversed completely
	if (!head2)	temp->next = head1; //list2 is traversed completely
	return head;
}

int main()
{
	starter();
	Node *head1 = NULL, *head2 = NULL;
	head1 = new Node(1);
	head1->next = new Node(2);
	head1->next->next = new Node(4);
	head2 = new Node(1);
	head2->next = new Node(3);
	head2->next->next = new Node(4);
	Node *head = merge_two_sorted_lists(head1, head2);
	print_ll(head);
	return 0;
}