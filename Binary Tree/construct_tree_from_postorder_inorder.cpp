
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

unordered_map<int, int>idx;

Node* buildTree(vi &postorder, vi &inorder, int &curr, int ins, int ine)
{

	if (ine < ins)	return NULL;

	Node *root = new Node(postorder[curr]);

	int mid = idx[postorder[curr]];

	curr--;

	root->right = buildTree(postorder, inorder, curr, mid + 1, ine);
	root->left = buildTree(postorder, inorder, curr, ins, mid - 1);

	return root;
}

void preorder(Node *root)
{
	if (!root)	return ;

	cout << root->val << " ";

	preorder(root->left);
	preorder(root->right);
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
	vi postorder(n), inorder(n);
	cin >> postorder >> inorder;

	for (int i = 0; i < n; i++)	idx[inorder[i]] = i;

	int curr = n - 1;
	Node *root = buildTree(postorder, inorder, curr, 0, n - 1);

	preorder(root);

	return 0;
}
