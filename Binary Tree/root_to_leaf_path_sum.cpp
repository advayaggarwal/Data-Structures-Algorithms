
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

//function to check if targetSum is achievable
void isPossible(Node *root, int targetSum, bool &found)
{
	if (!root)	return ;

	targetSum -= root->val;

	if (!root->left && !root->right && targetSum == 0)
	{
		found = true;
		return;
	}

	if (root->left)
	{
		isPossible(root->left, targetSum, found);
		if (found)	return; //Optimisation
	}

	if (root->right)
	{
		isPossible(root->right, targetSum, found);
		if (found)	return; //Optimisation
	}
}

//function to find all paths having sum as targetSum
void findPaths(Node *root, int targetSum, vector<vi>&paths, vi &path)
{
	if (!root)   return;

	targetSum -= root->val;
	path.push_back(root->val);

	if (!root->left and !root->right and targetSum == 0) //found path having sum as targetSum
	{
		paths.push_back(path);
		return;
	}

	if (root->left)
	{
		findPaths(root->left, targetSum, paths, path);
		path.pop_back();
	}

	if (root->right)
	{
		findPaths(root->right, targetSum, paths, path);
		path.pop_back();
	}
}

//function to find path having maximum sum, and its sum
void maxSumPath(Node *root, int currSum, int &maxSum, vi &route, vi &sol)
{
	if (!root)	return ;

	currSum += root->val;
	route.push_back(root->val);

	if (!root->left and !root->right)
	{
		if (currSum > maxSum)
		{
			maxSum = currSum;
			sol = route;
		}
		return ;
	}

	if (root->left)
	{
		maxSumPath(root->left, currSum, maxSum, route, sol);
		route.pop_back();
	}

	if (root->right)
	{
		maxSumPath(root->right, currSum, maxSum, route, sol);
		route.pop_back();
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

	int targetSum;
	cin >> targetSum;

	bool found = false;

	isPossible(root, targetSum, found); //function to check if targetSum is achievable

	cout << found << endl;

	vector<vi>paths;
	vi path;
	findPaths(root, targetSum, paths, path); //function to find all paths having sum as targetSum

	for (auto path : paths)
	{
		for (int e : path)	cout << e << " ";
		cout << endl;
	}

	int maxSum = INT_MIN;
	vi route, sol;
	maxSumPath(root, 0, maxSum, route, sol); //function to find path having maximum sum, and its sum

	if (maxSum != INT_MIN)
	{
		cout << "Path having maximum sum as " << maxSum << " is ";

		for (int x : sol)	cout << x << "->";
		cout << "X";
	}
	else cout << "Tree is empty!";
	return 0;
}
