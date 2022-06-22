/*
	AUTHOR:			ADVAY AGGARWAL
*/

#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long int
#define test_cases(x)	int x; cin>>x; while(x--)
#define vi vector<int>
#define setbits(x)      __builtin_popcountll(x)
#define endl "\n"


template <typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
	int n = vec.size();
	for (int i = 0; i < n; i++)	in >> vec[i];
	return in;
}

template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
	for (auto &val : vec)	out << val << " ";
	return out;
}

void starter()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

class Node
{
public:
	int val;
	Node *left, *right;

	Node()
	{
		val = 0;
		left = NULL;
		right = NULL;
	}

	Node(int x)
	{
		val = x;
		left = NULL;
		right = NULL;
	}

};

Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')	return NULL;

	// Creating vector of strings from input
	// string after splitting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; ) ip.push_back(str);


	// Create the root of the tree
	Node* root = new Node(stoi(ip[0]));

	// Push the root to the queue
	queue<Node*> queue;
	queue.push(root);

	// Starting from the second element
	int i = 1;
	while (!queue.empty() && i < ip.size())
	{

		// Get and remove the front of the queue
		Node* currNode = queue.front();
		queue.pop();

		// Get the current node's value from the string
		string currVal = ip[i];

		// If the left child is not null
		if (currVal != "N")
		{

			// Create the left child for the current node
			currNode->left = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->left);
		}

		// For the right child
		i++;
		if (i >= ip.size())	break;

		currVal = ip[i];

		// If the right child is not null
		if (currVal != "N")
		{

			// Create the right child for the current node
			currNode->right = new Node(stoi(currVal));

			// Push it to the queue
			queue.push(currNode->right);
		}

		i++;
	}

	return root;
}

//Without stack
void zigzag(Node *root)
{
	if (!root)	return;

	queue<Node*>q;
	q.push(root);

	int flag = 1;

	while (!q.empty())
	{
		int n = q.size();
		vi level(n);
		for (int i = 0; i < n; i++)
		{
			Node *temp = q.front();
			q.pop();

			int index = flag ? i : n - 1 - i;
			level[index] = temp->val;
			if (temp->left)	q.push(temp->left);
			if (temp->right)	q.push(temp->right);
		}

		for (int i = 0; i < n; i++)	cout << level[i] << " ";
		flag = !flag;
	}
}


//With deque or 2 stacks
void zigZag(Node *root)
{
	if (!root)	return;

	deque<Node*>q;

	q.push_back(root);
	cout << root->val << " ";

	// set ltr as false, because root is
	// already been taken care of.
	bool ltr = false; //left to right

	while (!q.empty())
	{
		int n = q.size();

		for (int i = 0; i < n; i++)
		{
			Node *temp;

			// popping mechanism
			if (ltr)
			{
				temp = q.back();
				q.pop_back();
			}

			else
			{
				temp = q.front();
				q.pop_front();
			}

			// pushing mechanism
			if (ltr)
			{
				if (temp->left)
				{
					q.push_front(temp->left);
					cout << temp->left->val << " ";
				}
				if (temp->right)
				{
					q.push_front(temp->right);
					cout << temp->right->val << " ";
				}

			}

			else
			{
				if (temp->right)
				{
					cout << temp->right->val << " ";
					q.push_back(temp->right);
				}
				if (temp->left)
				{
					cout << temp->left->val << " ";
					q.push_back(temp->left);
				}
			}

		}

		ltr = !ltr;
	}
}

// With 2 stacks
void ZigZag(Node *root)
{
	stack<Node*>s1, s2;
	s1.push(root);

	while (!s1.empty() or !s2.empty())
	{
		while (!s1.empty())
		{
			Node *temp = s1.top();
			s1.pop();
			cout << temp->val << " ";

			if (temp->left)	s2.push(temp->left);
			if (temp->right)	s2.push(temp->right);
		}

		while (!s2.empty())
		{
			Node *temp = s2.top();
			s2.pop();
			cout << temp->val << " ";

			if (temp->right)	s1.push(temp->right);
			if (temp->left)	s1.push(temp->left);
		}
	}
}

/*

		 1
		/ \
	   2   3
	  / \   \
	 4   5   6

*/

int main()
{
	starter();
	string s; // "1 2 3 4 5 N 6", fill string level by level, and for NULL put N
	getline(cin, s);

	Node* root = buildTree(s);
	zigzag(root);
	cout << endl;
	zigZag(root);
	cout << endl;
	ZigZag(root);

	return 0;
}