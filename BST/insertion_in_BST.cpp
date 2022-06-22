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
	for (string str; iss >> str; )	ip.push_back(str);

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

// Starting from root, each time move to the left or right child. Once we reach a leaf node, insert the key.
Node* insert(Node *root, int key)
{
	if (!root)
	{
		Node *new_node = new Node(key);
		return new_node;
	}

	if (key == root->val)	return root; //Stated in the ques, we can remove it also

	else if (key > root->val)	root->right = insert(root->right, key);

	else root->left = insert(root->left, key);

	return root;
}

Node* insertIntoBST(Node *root, int key)
{
	Node *curr = root, *node = new Node(key);

	while (curr)
	{
		if (curr->val > key)
		{
			if (curr->left)	curr = curr->left;

			else
			{
				curr->left = node;
				break;
			}
		}

		else
		{
			if (curr->right)	curr = curr->right;

			else
			{
				curr->right = node;
				break;
			}
		}
	}

	return root ? root : node;
}

void inorder(Node *root)
{
	if (!root)	return;

	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}


/*

		 1
		/ \
	   2   3
	  / \   \
	 4   5   6

*/

//Given a BST and a key K. If K is not present in the BST, Insert a new Node with a value equal to K into the BST.
//Note: If K is already present in the BST, don't modify the BST.

int main()
{
	starter();
	string s; //fill string level by level, and for NULL put N, eg 1 2 3 4 5 N 6
	getline(cin, s);
	Node* root = buildTree(s);

	int key;
	cin >> key;

	root = insert(root, key);

	inorder(root);

	return 0;
}