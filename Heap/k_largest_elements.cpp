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

void kLargestElements(vi &v, int k)
{
	priority_queue<int, vi, greater<int>>minHeap;

	for (int i = 0; i < v.size(); i++)
	{
		minHeap.push(v[i]);

		if (minHeap.size() > k)	minHeap.pop();
	}

	while (!minHeap.empty())
	{
		cout << minHeap.top() << " ";
		minHeap.pop();
	}
}

int main()
{
	starter();

	int n, k;
	cin >> n >> k;

	vi v(n);
	cin >> v;

	kLargestElements(v, k);

	return 0;
}