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

// We have used reference(&) because the return type of functions is void, or we can simply return head, or we can use double pointers

void insert_at_front(Node* &head, int data) //O(1)
{
	Node* temp = new Node(data);
	//temp->data = data;
	temp->next = head;
	head = temp;
}

void insert_at_end(Node* &head, int data) //O(n)
{
	Node* n = new Node(data);
	//n->data = data;
	n->next = NULL;
	if (head == NULL)
	{
		head = n;
		return;
	}
	else {
		Node*temp = head;
		while (temp->next != NULL) // Traverse till the last element of LL
		{
			temp = temp->next;
		} //temp starts pointing to last node
		temp->next = n;
	}
}

void insert_at_middle(Node* &head, int index, int data) //O(n)
{
	if (index < 0) return;
	if (index == 0)	insert_at_front(head, data);
	else
	{
		Node* n = new Node(data);
		//n->data = data;
		Node* temp = head;
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->next;
		}//temp starts pointing to the element after which we have to insert
		n->next = temp->next; // First update n->next, before changing temp->next, otherwise we'll lose the info
		temp->next = n;
	}
}

void delete_at_front(Node* &head) //O(1)
{
	Node* temp = head;
	head = head->next;
	delete(temp);
}

void delete_at_end(Node* &head) //O(n)
{
	Node* temp = head;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	delete(temp->next);
	temp->next = NULL;
}

void delete_at_middle(Node* &head, int index) //O(n)
{
	if (index == 0)
	{
		delete_at_front(head);
		return;
	}
	Node* temp = head;
	for (int i = 0; i < index - 1; i++)
	{
		temp = temp->next;
	} //temp starts pointing to one element before the element which we have to delete
	Node* to_delete = temp->next;
	temp->next = temp->next->next;
	delete(to_delete);
}

void delete_ll(Node* &head) //O(n)
{
	Node* current = head;
	Node* temp;
	while (current != NULL)
	{
		temp = current->next;
		delete (current);
		current = temp;
	}//current becomes NULL
	// or head = NULL;
	head = current; // So that head remains consistent, i.e. it doesn't start pointing to some garbage value
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

void print_recursive(Node* head)
{
	if (head == NULL)	return;
	cout << head->data << " ";
	print_recursive(head->next);
}

int main()
{
	starter();
	Node* head = NULL;
	int n;
	cin >> n;
	while (n--)
	{
		int data;
		cin >> data;
		//insert_at_front(head, data);
		insert_at_end(head, data);
	}
	print_ll(head);
	cout << endl;
	insert_at_middle(head, 3, 40);
	print_ll(head);
	delete_at_front(head);
	cout << endl;
	print_ll(head);
	delete_at_end(head);
	cout << endl;
	print_ll(head);
	delete_at_middle(head, 1);
	cout << endl;
	print_ll(head);
	delete_ll(head);
	cout << endl;
	print_ll(head);
	return 0;
}