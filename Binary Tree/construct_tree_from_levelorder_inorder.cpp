
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

vi find(vi &levelorder, vi &inorder, int start, int end) //O(N)
{
	vi res;

	for (int i = 0; i < levelorder.size(); i++)
	{
		if (idx[levelorder[i]] >= start and idx[levelorder[i]] <= end)	res.push_back(levelorder[i]);
	}
	return res;
}

Node* buildTree(vi levelorder, vi inorder) //O(N^2), visiting each node once and calling find() for it
{

	if (inorder.size() == 0 || levelorder.size() == 0)	return NULL;

	Node *root = new Node(levelorder[0]);

	int mid = idx[levelorder[0]];

	//search for elements for left subtree in levelorder through inorder
	vi left = find(levelorder, inorder, 0, mid - 1);

	//search for elements for right subtree in levelorder through inorder
	vi right = find(levelorder, inorder, mid + 1, inorder.size() - 1);

	root->left = buildTree(left, inorder);
	root->right = buildTree(right, inorder);

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

int main()
{
	starter();
	int n;
	cin >> n;
	vi levelorder(n), inorder(n);
	cin >> levelorder >> inorder;

	for (int i = 0; i < n; i++)	idx[inorder[i]] = i;

	Node* root = buildTree(levelorder, inorder);

	Preorder(root);

	return 0;
}
