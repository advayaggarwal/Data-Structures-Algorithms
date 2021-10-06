
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
	char val;
	Node *left, *right;

	Node()
	{
		val = 0;
		left = NULL;
		right = NULL;
	}

	Node(char x)
	{
		val = x;
		left = NULL;
		right = NULL;
	}

};

bool isOperator(char c)
{
	return c == '+' or c == '-' or c == '*' or c == '/';
}

Node* buildTree(vector<char>&exp, int &index)
{

	if (index == exp.size())	return NULL;

	Node *root = new Node(exp[index]);

	if (isOperator(exp[index++]))
	{
		root->left = buildTree(exp, index);
		root->right = buildTree(exp, index);
	}

	return root;
}


void preorder(Node *root)
{
	if (!root)	return;

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

	vector<char>exp(n);
	cin >> exp;

	int index = 0;
	Node* root = buildTree(exp, index);

	preorder(root);

	return 0;
}
