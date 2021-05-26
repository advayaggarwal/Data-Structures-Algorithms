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

void set_frequency(vi &fre, int a, int x) //O(log2n)
//x=1 => increase the frequency if that particular bit is set, else decrease the frequency
{
	for (int i = 0; i < 31; i++)
	{
		if (a & (1 << i))	fre[i] += x;
	}
}

ll cal_or(vi &fre) //O(log2n)
{
	ll ans = 0;
	for (int i = 0; i < 32; i++)
	{
		if (fre[i])
		{
			ans += (1 << i);
		}
	}
	return ans;
}

int main()
{
	starter();
	test_cases(t)
	{
		int n, q;
		cin >> n >> q;
		vi a(n);
		vi fre(32, 0);
		int ans = 0;

		//OR of the ANDs of all the elements of the non empty subarrays is just OR of all the array elements

		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			set_frequency(fre, a[i], 1);
			ans |= a[i];
		}
		cout << ans << endl;
		while (q--)
		{
			int x, v;
			cin >> x >> v;
			set_frequency(fre, a[x - 1] , -1);
			a[x - 1] = v;
			set_frequency(fre, a[x - 1], 1);
			cout << cal_or(fre) << endl;
		}
	}
	return 0;
}