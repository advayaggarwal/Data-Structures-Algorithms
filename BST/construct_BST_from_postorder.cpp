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

Node* buildTree(vi &postorder, int &index, int l, int r)
{
	if (index < 0)	return NULL;

	if (postorder[index] >= l and postorder[index] <= r)
	{
		Node *root = new Node(postorder[index--]);

		root->right = buildTree(postorder, index, root->val + 1, r);
		root->left = buildTree(postorder, index, l, root->val - 1);

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

	vi postorder(n);
	cin >> postorder;

	int index = n - 1;
	Node* root = buildTree(postorder, index, INT_MIN, INT_MAX);

	inorder(root);

	return 0;
}