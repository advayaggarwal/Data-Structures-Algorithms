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


void topView(Node *root, vi &res)
{
	if (!root)	return;

	queue<pair<Node*, int>>q; //{Node*, horizontal distance}
	q.push({root, 0});
	map<int, int>m; //{horizontal distance, node}
	while (!q.empty())
	{
		Node *temp = q.front().first;
		int distance = q.front().second;
		q.pop();

		if (m.find(distance) == m.end())
		{
			//res.push_back(temp->val); //we can push here also but in ques it is given that we've to print the nodes
			// in increasing order of horizontal distance
			m[distance] = temp->val;
		}

		if (temp->left)	q.push({temp->left, distance - 1});
		if (temp->right)	q.push({temp->right, distance + 1});
	}

	//To maintain the order given in the ques. i.e. increasing order of horizontal distance
	for (auto p : m)
	{
		res.push_back(p.second);
	}

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
	topView(root, res);

	for (int x : res)	cout << x << " ";

	return 0;
}
