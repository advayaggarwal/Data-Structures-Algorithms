/*
	AUTHOR:			ADVAY AGGARWAL
	INSTITUTION:	IIIT DHARWAD
*/
#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long int
#define test_cases(x)	int x; cin>>x; while(x--)
#define vi vector<int>
#define setbits(x)      __builtin_popcountll(x)
#define endl "\n"

void starter()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}


int main()
{
	starter();
	test_cases(t)
	{
		int n, k;
		cin >> n >> k;
		set<int> v;
		for (int i = 1; i <= n; i++)	v.insert(i);
		if (n >= k)	v.erase(k);

		int e = 1;
		while (v.size() > 0 && e < k)
		{
			if ((v.find(k - e) != v.end()) && (k - e != e))
			{
				v.erase(e);
			}
			e++;

		}

		cout << v.size() << endl;

		if (v.size() > 0)
		{
			for (auto e : v)	cout << e << " ";
			cout << endl;
		}
	}
	return 0;
}