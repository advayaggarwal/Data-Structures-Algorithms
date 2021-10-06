
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

// void path(Node *root1, Node *root2, int distance, int &ans) //gives the distance between 2 nodes
// {

// 	if (!root1)	return ;

// 	if (root1 == root2)
// 	{
// 		ans = distance;
// 		return;
// 	}

// 	path(root1->left, root2, distance + 1, ans);
// 	path(root1->right, root2, distance + 1, ans);

// }

int distance(Node *root1, Node *root2)
{
	if (!root1)	return -1;

	if (root1 == root2)	return 0;

	int d1 = distance(root1->left, root2);
	int d2 = distance(root1->right, root2);

	if (d1 != -1)	return d1 + 1;
	if (d2 != -1)	return d2 + 1;

	return -1;
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

	if (p_root and q_root)
	{
		Node *lca = LCA(root, p_root, q_root);

		int distance1 = distance(lca, p_root); //distance1 is the distance from lca to p_root
		int distance2 = distance(lca, q_root); //distance2 is the distance from lca to q_root
		cout << distance1 + distance2;
	}

	else cout << -1;

	return 0;
}