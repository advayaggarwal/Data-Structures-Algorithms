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

class compare
{
public:
	bool operator()(int a, int b)
	{
		return a > b;
	}
};

int main()
{
	starter();

	int n;
	cin >> n;

	vi v(n);
	cin >> v;

	priority_queue<int, vi, compare>heap;

	for (int x : v)	heap.push(x);

	while (!heap.empty())
	{
		cout << heap.top() << " ";
		heap.pop();
	}

	return 0;
}