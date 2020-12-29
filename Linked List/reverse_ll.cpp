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

class Node
{
public:
	int data;
	Node* next;
};

void insert_at_front(Node* &head, int data) //O(1)
{
	Node* temp = new Node;
	temp->data = data;
	temp->next = head;
	head = temp;
}

void reverse_iterative(Node* &head)
{
	Node* current = head;
	Node* prev = NULL;
	Node* next;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}//current and next will point to NULL after coming out of while loop
	/*NULL <--- 1 <--- 2 <--- 3		NULL

	   		    ^			  ^		^  ^
	   		    |			  |		|  |
	   			|			  |		|  |
	   		  head		    prev  cur next

	*/
	head = prev; //Make sure to update the head pointer, for understanding see the above diagram
}

Node* reverse_recursive(Node* &head)
{
	if (head->next == NULL)
	{
		return head;
	}
	Node* temp = reverse_recursive(head->next);
	head->next->next = head;
	head->next = NULL;
	return temp;
}

void print_ll(Node*head) //O(n) , visiting every node once
{
	//Node* temp = head;
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
	insert_at_front(head, 5);
	insert_at_front(head, 4);
	insert_at_front(head, 3);
	insert_at_front(head, 2);
	insert_at_front(head, 1);
	print_ll(head);
	cout << endl;
	head = reverse_recursive(head);
	print_ll(head);
	cout << endl;
	reverse_iterative(head);
	print_ll(head);
	return 0;
}