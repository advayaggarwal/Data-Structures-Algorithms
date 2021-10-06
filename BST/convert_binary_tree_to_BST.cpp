
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

void preorder(Node *root, vi &nodes)
{
	if (!root)	return;

	nodes.push_back(root->val);

	preorder(root->left, nodes);
	preorder(root->right, nodes);
}

void binaryTreeToBST(Node *root, vi &nodes, int &index)
{
	if (!root)	return ;

	binaryTreeToBST(root->left, nodes, index);

	root->val = nodes[index++];

	binaryTreeToBST(root->right, nodes, index);
}

void inorder(Node *root) //Just to check if our inorder function is working fine
{
	if (!root)	return ;

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

int main()
{
	starter();
	string s; //fill string level by level, and for NULL put N, eg 1 2 3 4 5 N 6
	getline(cin, s);
	Node* root = buildTree(s);

	vi nodes;

	preorder(root, nodes); //Do any traversal and store the nodes values

	sort(nodes.begin(), nodes.end()); //So that we can compare the values with inorder traveral of the given tree

	int index = 0;
	binaryTreeToBST(root, nodes, index); //Do inorder traversal and replace the values

	inorder(root);
	return 0;
}
