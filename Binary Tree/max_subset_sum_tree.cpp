
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

//Inclusion sum = root->val + left.exc + right.exc => if root is included, definitely we can't include left and right
//Exclusion sum = max(left.inc,left.exc) + max(right.inc, right.exc) => root is excluded, we can include as well as
// exclude both left and right

//Time complexity - O(N), visiting every node only once, and doing O(1) work at every node
pair<int, int> maxSubsetSum(Node *root) //{inc, exc} first - inclusion sum, second - exclusion sum
{

	if (!root)	return {0, 0};

	pair<int, int>left = maxSubsetSum(root->left);
	pair<int, int>right = maxSubsetSum(root->right);

	pair<int, int> p;

	//if included, we have to exclude both the children
	p.first = root->val + left.second + right.second;

	//if excluded, we may or may not include the children
	p.second = max(left.first, left.second) + max(right.first, right.second);

	return p;

}

/*

		 1
		/ \
	   2   3
	  / \   \
	 4   5   6

*/

/*
==== Find the largest sum of a subset of nodes in a binary tree, such that if a node is included in the sum
==== then its parent and children must not be included in the subset sum.
*/

int main()
{
	starter();
	string s; //fill string level by level, and for NULL put N, eg 1 2 3 4 5 N 6
	getline(cin, s);
	Node* root = buildTree(s);


	pair<int, int>ans = maxSubsetSum(root);

	cout << max(ans.first, ans.second);

	return 0;
}
