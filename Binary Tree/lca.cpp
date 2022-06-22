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

Node* find_by_value(Node *root, int target)
{
	if (!root)	return NULL;

	if (root->val == target)	return root;

	Node *n1 = find_by_value(root->left, target);
	if (n1)	return n1;

	Node *n2 = find_by_value(root->right, target);
	if (n2)	return n2;

	return NULL;
}

//Recursive
//Time complexity - O(N)
//Space complexity - O(N)
Node* LCA(Node *root, Node *p_root, Node *q_root)
{
	if (!root)	return NULL;

	if (root->val == p_root->val or root->val == q_root->val)	return root;

	Node *l = LCA(root->left, p_root, q_root);
	Node *r = LCA(root->right, p_root, q_root);

	if (l and r)	return root;

	if (l)	return l;
	if (r)	return r;

	return NULL;
}

bool findPath(Node *root, int key, vector<Node*>&path)
{
	if (!root)   return false;

	path.push_back(root);

	if (root->val == key)    return true;

	if (findPath(root->left, key, path) or findPath(root->right, key, path)) return true;

	path.pop_back();
	return false;
}

//Time complexity - O(N)
//Space complexity - O(N)
Node* lowestCommonAncestor(Node* root, Node* p, Node* q)
{
	vector<Node*>path1, path2;
	findPath(root, p->val, path1);
	findPath(root, q->val, path2);

	int m = path1.size(), n = path2.size();

	Node *ans;

	for (int i = 0, j = 0; i < m && j < n; i++, j++)
	{
		if (path1[i] == path2[j])    ans = path1[i];
		else break;
	}

	return ans;
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

	int p, q;
	cin >> p >> q;

	Node *p_root = find_by_value(root, p);
	Node *q_root = find_by_value(root, q);

	Node *lca = LCA(root, p_root, q_root);
	Node *LCA = lowestCommonAncestor(root, p_root, q_root);

	cout << lca->val << endl << LCA->val;

	return 0;
}