
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

// Do level order traversal, and in each level, put the last node of that level into the result
void rightView(Node *root, vi &res)
{
	if (!root)	return;

	queue<Node*>q;
	q.push(root);

	while (!q.empty())
	{
		int size = q.size();
		res.push_back(q.back()->val); //last element in queue is the last node of that particular level in levelorder traversal
		while (size--)
		{
			Node *temp = q.front();
			q.pop();

			if (temp->left)	q.push(temp->left);
			if (temp->right)	q.push(temp->right);
		}
	}
}

/* Idea
We will push one element at each level. So, the size of the res vector will actually be equal to the number of levels
we have already stored the result. If the level of some element is more than the size of res vector that means this
will be a new level for which we have not pushed anything in the res vector. So, we will push this element in the res
vector. The size of res in next iterations will increase by one and for all the other elements in same level
res.size() < level will be false
*/

//Modified preorder traversal
void rightViewRecursive(Node *root, int level, vi &res)
{
	if (!root)	return;
	if (res.size() < level)	res.push_back(root->val);

	rightViewRecursive(root->right, level + 1, res);
	rightViewRecursive(root->left, level + 1, res);
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

	vi res;
	rightView(root, res);
	rightViewRecursive(root, 1, res);
	for (int e : res)	cout << e << " ";

	return 0;
}
