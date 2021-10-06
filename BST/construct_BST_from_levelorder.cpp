
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

//Time complexity - O(n^2)
//Space complexity - O(n)
Node* buildTree(vi levelorder)
{
	if (levelorder.size() == 0)	return NULL;

	Node *root = new Node(levelorder[0]);

	vi l, r;

	//Pushing smaller elements in l vector and greater elements in r vector, to make left and right subtree respectively
	for (int i = 1; i < levelorder.size(); i++)
	{
		if (levelorder[i] < levelorder[0])	l.push_back(levelorder[i]);
		else r.push_back(levelorder[i]);
	}

	//Deleting levelorder vector, now we don't need it, got it in left and right vector, else S.C would be O(n^2)
	//You can call clear, and that will destroy all the objects, but that will not free the memory.

	levelorder.clear(); //Removes all elements making size 0, but capacity is intact
	levelorder.shrink_to_fit(); //It would theoretically shrink the capacity to fit the size (which is now 0).

	root->left = buildTree(l);
	root->right = buildTree(r);

	return root;
}

void inorder(Node *root)
{
	if (!root)	return ;

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
	vi levelorder(n);
	cin >> levelorder;

	Node* root = buildTree(levelorder);

	inorder(root);

	return 0;
}
