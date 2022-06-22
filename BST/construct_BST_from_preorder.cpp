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

Node* buildTree(vi &preorder, int &index, int n, int l, int r)
{
	if (index == n)	return NULL;

	if (preorder[index] >= l and preorder[index] <= r)
	{
		Node *root = new Node(preorder[index++]);

		root->left = buildTree(preorder, index, n, l, root->val - 1);
		root->right = buildTree(preorder, index, n, root->val + 1, r);

		return root;
	}

	return NULL;
}

void inorder(Node *root)
{
	if (!root)	return;

	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
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

	int n;
	cin >> n;

	vi preorder(n);
	cin >> preorder;

	int index = 0;
	Node* root = buildTree(preorder, index, n, INT_MIN, INT_MAX);

	inorder(root);

	return 0;
}