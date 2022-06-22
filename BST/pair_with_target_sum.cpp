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

//Method 1- storing inorder traversal + two pointers
//Time complexity - O(n)
//Space complexity - O(n)

void inorder(Node * root, vector<int>&v)
{
	if (!root)   return;

	inorder(root->left, v);

	v.push_back(root->val);

	inorder(root->right, v);
}

pair<int, int> findPair(vi & v, int l, int r, const int &target)
{
	while (l < r)
	{
		if (v[l] + v[r] == target)
		{
			return {v[l], v[r]};
		}

		else if (v[l] + v[r] < target)	l++;
		else r--;
	}

	return { -1, -1};
}


//Method 2 - Using iterative inorder traversal
//Time complexity - O(n)
//Space complexity - O(h)

void pushElements(Node *root, stack<Node*>&s, bool l_direction)
{
	if (l_direction)
	{
		while (root)
		{
			s.push(root);
			root = root->left;
		}
	}

	else
	{
		while (root)
		{
			s.push(root);
			root = root->right;
		}
	}
}

pair<int, int> find_pair(Node *root, const int &target)
{
	if (!root)	return { -1, -1};

	stack<Node*>s1, s2;

	pushElements(root, s1, true);
	pushElements(root, s2, false);

	while (!s1.empty() && !s2.empty() && s1.top()->val < s2.top()->val)
	{
		int x = s1.top()->val;
		int y = s2.top()->val;

		if (x + y == target)	return {x, y};

		else if (x + y < target)
		{
			Node *temp = s1.top();
			s1.pop();
			pushElements(temp->right, s1, true);
		}

		else
		{
			Node *temp = s2.top();
			s2.pop();
			pushElements(temp->left, s2, false);
		}
	}

	return { -1, -1};
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

	int target;
	cin >> target;

	vi v;
	inorder(root, v);

	pair<int, int>p1 = findPair(v, 0, v.size() - 1, target);

	cout << p1.first << " " << p1.second << endl;

	pair<int, int>p2 = find_pair(root, target);

	cout << p2.first << " " << p2.second;

	return 0;
}
