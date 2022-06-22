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


Node* find(Node *root, int target)
{
	if (!root)   return NULL;

	if (root->val == target)    return root;

	Node *n1 = find(root->left, target);

	if (n1)  return n1;

	Node *n2 = find(root->right, target);
	if (n2)  return n2;

	return NULL;
}

void fillParent(Node *root, unordered_map<Node*, Node*>&parent)
{
	if (!root)   return;

	if (root->left)
	{
		parent[root->left] = root;
		fillParent(root->left, parent);
	}

	if (root->right)
	{
		parent[root->right] = root;
		fillParent(root->right, parent);
	}
}

//Intuition

//If we know the parent of every node x, we know all nodes that are distance 1 from x.
//We can then perform a breadth first search from the target node to find the answer.

vector <int> kDistanceNodes(Node* root, int target , int k)
{
	// return the sorted vector of all nodes at k dist

	if (!root)   return {};
	if (k == 0)    return {target};

	vector<int>ans;
	Node *target_node = find(root, target);

	unordered_map<Node*, Node*>parent;
	parent[root] = NULL;
	fillParent(root, parent);

	unordered_set<int>visited;

	queue<Node*>q;
	q.push(target_node);

	while (!q.empty() and k)
	{
		int size = q.size();

		while (size--)
		{
			Node *temp = q.front();
			visited.insert(temp->val);
			q.pop();

			if (temp->left and visited.find(temp->left->val) == visited.end())
			{
				q.push(temp->left);
			}

			if (temp->right and visited.find(temp->right->val) == visited.end())
			{
				q.push(temp->right);
			}

			if (parent[temp] and visited.find(parent[temp]->val) == visited.end())
			{
				q.push(parent[temp]);
			}
		}

		k--;
	}

	while (!q.empty())
	{
		ans.push_back(q.front()->val);
		q.pop();
	}

	//sort(ans.begin(), ans.end()); //to get the ans in sorted order
	return ans;
}


//Method 2

void printAtLevelK(Node *root, int k)
{
	if (!root)	return ;

	if (k == 0)
	{
		cout << root->val << " ";
		return ;
	}

	printAtLevelK(root->left, k - 1);
	printAtLevelK(root->right, k - 1);

}

int printNodesAtDistanceK(Node *root, Node *target, int k) //returns the distance of node from target node
{

	if (!root)	return -1;

	//reached the target node
	if (root == target)
	{
		printAtLevelK(target, k);
		return 0;
	}

	int DL = printNodesAtDistanceK(root->left, target, k);

	if (DL != -1)
	{
		//Print the current node
		if (DL + 1 == k)
		{
			cout << root->val << " ";
		}

		//or print some nodes in the right subtree
		else
		{
			printAtLevelK(root->right, k - 2 - DL);
		}

		return 1 + DL;
	}

	int DR = printNodesAtDistanceK(root->right, target, k);

	if (DR != -1)
	{
		//Print the current node
		if (DR + 1 == k)
		{
			cout << root->val << " ";
		}

		//or print some nodes in the left subtree
		else
		{
			printAtLevelK(root->left, k - 2 - DR);
		}

		return 1 + DR;
	}

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
	int target;
	cin >> target;
	int k;
	cin >> k;

	vi ans = kDistanceNodes(root, target, k);

	for (int x : ans)	cout << x << " ";

	cout << endl;

	Node *target_node = find(root, target);
	printNodesAtDistanceK(root, target_node, k);

	return 0;
}