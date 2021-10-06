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

//Using Min Heap
//Time complexity - O(n + k*logn)
//Space complexity - O(n)
int kthSmallestElement(vi &v, int k)
{
	priority_queue<int, vi, greater<int>>heap;

	for (int x : v)	heap.push(x);

	int ans = INT_MIN;

	while (k--)
	{
		ans = heap.top();
		heap.pop();
	}

	return ans;
}

//Using Max Heap
//Time complexity - O(n*logk)
//Space complexity - O(k)
int kThSmallestElement(vi &v, int k)
{
	priority_queue<int>heap;

	for (int i = 0; i < v.size(); i++)
	{
		heap.push(v[i]);

		if (i >= k)	heap.pop();
	}

	return heap.top();

}

int main()
{
	starter();

	int n, k;
	cin >> n >> k;

	vi v(n);
	cin >> v;

	cout << kthSmallestElement(v, k) << endl << kThSmallestElement(v, k);

	return 0;
}