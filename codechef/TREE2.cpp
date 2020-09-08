/*
	AUTHOR:			ADVAY AGGARWAL
	INSTITUTION:	IIIT DHARWAD
*/
#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long
#define test_cases(x)	int x; cin>>x; while(x--)

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

int count_distinct(int a[], int n)
{
	int unique_elements = 0;
	for (int i = 0; i < n; i++)
	{
		while (i < n - 1 && a[i] == a[i + 1])
		{
			i++;
		}
		unique_elements++;
	}
	return unique_elements;
}

int main()
{
	starter();
	test_cases(t)
	{
		int n, i;
		cin >> n;
		int a[n];
		for (i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		int ans = count_distinct(a, n);
		if (a[0] == 0)	cout << ans - 1 << endl;
		else cout << ans << endl;
	}
	return 0;
}