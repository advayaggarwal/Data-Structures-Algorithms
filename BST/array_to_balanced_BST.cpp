
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

void inorder(Node *root)
{
	if (!root)	return;

	inorder(root->left);
	cout << root->val << " ";
	inorder(root->right);
}

Node* buildTree(vi &v, int low, int high)
{
	if (low > high)	return NULL; //no element

	int mid = (low + high) / 2;

	Node *root = new Node(v[mid]);

	root->left = buildTree(v, low, mid - 1);
	root->right = buildTree(v, mid + 1, high);

	return root;
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

	vi v(n);
	cin >> v;

	sort(v.begin(), v.end()); //if already sorted, no need to sort the array

	Node *root = buildTree(v, 0, n - 1);

	inorder(root);

	return 0;
}
