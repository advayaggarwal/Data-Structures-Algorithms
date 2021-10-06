
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

// A function to store all left boundary nodes, except a leaf node.
void leftBoundary(Node *root, vi &res)
{
	if (!root)	return;

	if (root->left or root->right)	res.push_back(root->val); //root not a leaf node as will be covered in leaf nodes

	if (root->left)	leftBoundary(root->left, res); //preference is given to the left
	else leftBoundary(root->right, res);
}

//Do any traversal, if leaf node push into the res
void leafNodes(Node *root, vi &res) //using inorder
{
	if (!root)	return;

	leafNodes(root->left, res);
	if (!root->left and !root->right)	res.push_back(root->val); //i.e. a leaf node
	leafNodes(root->right, res);
}

// A function to store all right boundary nodes in bottom up manner, except a leaf node
void reverseRightBoundary(Node *root, vi &res)
{
	if (!root)	return ;

	if (root->right)	reverseRightBoundary(root->right, res);
	else reverseRightBoundary(root->left, res);

	if (root->left or root->right)	res.push_back(root->val); //root not a leaf node as will be covered in leaf nodes

}

/*

		 1
		/ \
	   2   3
	  / \   \
	 4   5   6

*/

int main() //O(n), where n is the number of nodes
{
	starter();
	string s; //fill string level by level, and for NULL put N, eg 1 2 3 4 5 N 6
	getline(cin, s);
	Node* root = buildTree(s);

	vi res;
	res.push_back(root->val);

	//i.e. tree doesn't contain only 1 node, otherwise it will come twice, in line 161 and again in leaf nodes

	if (root->left or root->right)
	{
		leftBoundary(root->left, res);
		leafNodes(root, res);
		reverseRightBoundary(root->right, res);
	}

	cout << res;
	return 0;
}
