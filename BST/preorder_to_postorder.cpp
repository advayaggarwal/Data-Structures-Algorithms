
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

int findNextGreater(vi &preorder, int l, int r)
{
	for (int i = l + 1; i <= r; i++)
	{
		if (preorder[i] > preorder[l])	return i;
	}

	return r + 1; //so that base condition handles this l > r, no need to write this case differently, (r+1, r) -> range
	//right part doesn't exist
}

void preorderToPostorder(vi &preorder, vi &postorder, int l, int r)
{
	if (l > r)	return;

	int g = findNextGreater(preorder, l, r);

	preorderToPostorder(preorder, postorder, l + 1, g - 1);
	preorderToPostorder(preorder, postorder, g, r);

	postorder.push_back(preorder[l]);
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

	vi postorder;

	preorderToPostorder(preorder, postorder, 0, n - 1);

	cout << postorder;

	return 0;
}
