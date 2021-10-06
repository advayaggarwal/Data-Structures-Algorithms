
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

void inorder(Node *root, vi &ans)
{
	if (!root)	return;

	inorder(root->left, ans);
	ans.push_back(root->val);
	inorder(root->right, ans);
}

vi mergeBST(Node *root1, Node* root2)
{
	vi res;

	if (!root1 and !root2)	return res;

	if (!root1)
	{
		inorder(root2, res);
		return res;
	}

	if (!root2)
	{
		inorder(root1, res);
		return res;
	}


	stack<Node*>stk1, stk2;

	while (root1 or !stk1.empty() or root2 or !stk2.empty())
	{
		while (root1 or root2)
		{
			if (root1)
			{
				stk1.push(root1);
				root1 = root1->left;
			}

			if (root2)
			{
				stk2.push(root2);
				root2 = root2->left;
			}
		}


		if (!stk1.empty() and !stk2.empty())
		{
			if (stk1.top()->val < stk2.top()->val)
			{
				res.push_back(stk1.top()->val);
				root1 = stk1.top()->right;
				stk1.pop();
			}

			else
			{
				res.push_back(stk2.top()->val);
				root2 = stk2.top()->right;
				stk2.pop();
			}
		}


		else if (!stk1.empty())
		{
			res.push_back(stk1.top()->val);
			root1 = stk1.top()->right;
			stk1.pop();
		}

		else if (!stk2.empty())
		{
			res.push_back(stk2.top()->val);
			root2 = stk2.top()->right;
			stk2.pop();
		}
	}

	return res;
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
	string s1, s2; //fill string level by level, and for NULL put N, eg 1 2 3 4 5 N 6
	getline(cin, s1);
	getline(cin, s2);

	Node* root1 = buildTree(s1);
	Node* root2 = buildTree(s2);

	vi res = mergeBST(root1, root2);
	cout << res;

	return 0;
}
