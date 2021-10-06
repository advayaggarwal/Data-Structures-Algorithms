
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

struct BST
{
	bool is_bst;
	int size; //size of largest BST in the subtree
	int min; //min value in the subtree
	int max; //max value in the subtree
	Node *lBstRoot; //root of largest BST in the subtree
};

BST largestBST(Node* root) //Postorder Traversal
{
	if (!root)
	{
		return {true, 0, INT_MAX, INT_MIN, NULL};
	}

	BST l = largestBST(root->left);
	BST r = largestBST(root->right);

	//Both the codes are right, but below one is more generic
	// if (l.is_bst and r.is_bst and root->val > l.max and root->val < r.min)
	// {
	// 	return {true, 1 + l.size + r.size, min(root->val, l.min), max(root->val, r.max)};
	// }

	// return {false, max(l.size, r.size), -1, -1}; //not a bst min max does not matter, we will only compare if its bst

	BST n;
	n.is_bst = l.is_bst and r.is_bst and root->val > l.max and root->val < r.min;

	if (n.is_bst)
	{
		n.size = 1 + l.size + r.size;
		n.lBstRoot = root;
	}

	else
	{
		if (l.size > r.size)
		{
			n.size = l.size;
			n.lBstRoot = l.lBstRoot;
		}

		else
		{
			n.size = r.size;
			n.lBstRoot = r.lBstRoot;
		}
	}

	n.min = min(root->val, min(l.min, r.min));
	n.max = max(root->val, max(l.max, r.max));

	return n;
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
	string s; //fill string level by level, and for NULL put N, eg 1 2 3 4 5 N 6
	getline(cin, s);
	Node* root = buildTree(s);

	BST b = largestBST(root);

	cout << "Size of largest BST rooted at " << b.lBstRoot->val << " is " << b.size;

	return 0;
}
