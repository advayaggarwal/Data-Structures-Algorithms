
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

Node* buildTree()
{
	int data;
	cin >> data;

	if (data == -1)	return NULL;

	Node *root = new Node(data);
	root->left = buildTree();
	root->right = buildTree();

	return root;
}

void levelOrder(Node *root)
{
	if (!root)	return;

	queue<Node*>q;
	q.push(root);

	while (!q.empty())
	{
		Node *temp = q.front();
		q.pop();
		cout << temp->val << " ";

		if (temp->left)	q.push(temp->left);
		if (temp->right)	q.push(temp->right);
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

	Node* root = buildTree(); //Preorder build

	levelOrder(root);

	return 0;
}
