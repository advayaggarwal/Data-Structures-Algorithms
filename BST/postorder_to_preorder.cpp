
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

int findNextSmaller(vi &postorder, int l, int r)
{
	for (int i = r - 1; i >= l; i--)
	{
		if (postorder[i] < postorder[r])	return i;
	}

	return l - 1; //so that base condition handles this l > r, no need to write this case differently, (l, l-1) -> range
	//left part doesn't exist
}

void postorderToPreorder(vi &postorder, vi &preorder, int l, int r)
{
	if (l > r)	return;

	preorder.push_back(postorder[r]);

	int s = findNextSmaller(postorder, l, r);

	postorderToPreorder(postorder, preorder, l, s);
	postorderToPreorder(postorder, preorder, s + 1, r - 1);
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

	vi preorder;

	postorderToPreorder(postorder, preorder, 0, n - 1);

	cout << preorder;

	return 0;
}
