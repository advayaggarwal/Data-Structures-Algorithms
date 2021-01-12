/*
	AUTHOR:			ADVAY AGGARWAL
	INSTITUTION:	IIIT DHARWAD
*/
#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long
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
		int w, h, n;
		cin >> w >> h >> n;
		int count = 1;
		if ((w & 1) && (h & 1) && (n != 1))	cout << "NO" << endl;
		else
		{
			while (!(w & 1) || !(h & 1))
			{
				if (count >= n)	break;
				if (!(h & 1))	h /= 2;
				else if (!(w & 1))	w /= 2;
				count *= 2;
			}
			//cout << count << endl;
			if (count >= n)	cout << "YES" << endl;
			else cout << "NO" << endl;
		}

	}
	return 0;
}