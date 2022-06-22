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

/*
int search(vi &inorder, int ins, int ine, int key) //We can use unordered map instead
{
	for (int i = ins; i <= ine; i++)
	{
		if (inorder[i] == key)	return i;
	}
	return -1;
}
*/

unordered_map<int, int>idx;

//O(N) using unordered map, and if using search function - O(N^2)
Node* buildTree(vi &preorder, vi &inorder, int &start, int ins, int ine) //ins-inorder start, ine-inorder end
{

	if (ine < ins)	return NULL;

	Node *root = new Node(preorder[start]);

	// int mid = search(inorder, ins, ine, preorder[start]); // O(n)
	int mid = idx[preorder[start]]; //O(1)
	start++;

	root->left = buildTree(preorder, inorder, start, ins, mid - 1);
	root->right = buildTree(preorder, inorder, start, mid + 1, ine);

	return root;
}

void Preorder(Node *root)
{
	if (!root)	return;

	cout << root->val << " ";
	Preorder(root->left);
	Preorder(root->right);
}

/*

		 1
		/ \
	   2   3
	  / \   \
	 4   5   6

*/

/*

The two key observations are:

Preorder traversal follows Root -> Left -> Right, therefore, given the preorder array preorder,
we have easy access to the root which is preorder[0].

Inorder traversal follows Left -> Root -> Right, therefore if we know the position of Root,
we can recursively split the entire array into two subtrees.

*/

int main()
{
	starter();
	int n;
	cin >> n;
	vi preorder(n), inorder(n);
	cin >> preorder >> inorder;

	for (int i = 0; i < n; i++)	idx[inorder[i]] = i;
	int start = 0;
	Node *root = buildTree(preorder, inorder, start, 0, n - 1);

	Preorder(root);
	return 0;
}