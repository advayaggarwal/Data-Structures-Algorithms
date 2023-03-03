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
#define pii pair<int,int>
#define vvi vector<vi>

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

struct segmentTree
{
	int n;
	vector<int>st;

	void init(int n)
	{
		this->n = n;
		st.resize(4 * n, 0);
	}

	void buildHelper(int start, int end, int node, vector<int>&v)
	{
		//base case - leaf node
		if (start == end)
		{
			st[node] = v[start];
			return;
		}

		int mid = start + (end - start) / 2;

		//left subtree is [start, mid]
		buildHelper(start, mid, 2 * node + 1, v);

		//right subtree is [mid+1, end]
		buildHelper(mid + 1, end, 2 * node + 2, v);

		st[node] = st[2 * node + 1] + st[2 * node + 2];
	}

	void build(vector<int> &v)
	{
		buildHelper(0, n - 1, 0, v);
	}

	int queryHelper(int start, int end, int l, int r, int node)
	{
		//non overlapping case
		if (start > r or end < l)	return 0;

		//complete overlap
		if (start >= l && end <= r)	return st[node];

		//partial overlap
		int mid = start + (end - start) / 2;
		int leftQuery = queryHelper(start, mid, l, r, 2 * node + 1);
		int rightQuery = queryHelper(mid + 1, end, l, r, 2 * node + 2);
		return leftQuery + rightQuery;
	}

	int query(int l, int r)
	{
		return queryHelper(0, n - 1, l, r, 0);
	}

	void updateHelper(int start, int end, int index, int val, int node)
	{
		//base case - leaf node
		if (start == end)
		{
			st[node] = val;
			return;
		}

		int mid = start + (end - start) / 2;

		if (index <= mid) //go to left subtree
		{
			updateHelper(start, mid, index, val, 2 * node + 1);
		}

		else //go to right subtree
		{
			updateHelper(mid + 1, end, index, val, 2 * node + 2);
		}

		st[node] = st[2 * node + 1] + st[2 * node + 2]; //update the parent
	}

	void update(int index, int val)
	{
		updateHelper(0, n - 1, index, val, 0);
	}
};

int main()
{
	starter();

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)	cin >> v[i];

	segmentTree tree;
	tree.init(v.size());
	tree.build(v);

	cout << tree.st[0];
	return 0;
}