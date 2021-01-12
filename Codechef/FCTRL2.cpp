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

int main()
{
	starter();
	test_cases(t)
	{
		int n, m = 1;
		cin >> n;
		int factorial[200] = {0};
		factorial[0] = 1;
		int i = 1;
		int temp , index;
		while (i <= n)
		{
			index = 0;
			temp = 0;
			while (index < m)
			{
				factorial[index] = factorial[index] * i + temp;
				temp = factorial[index] / 10;
				factorial[index] = factorial[index] % 10;
				index++;
			}
			while (temp != 0)
			{
				factorial[m] = temp % 10;
				temp /= 10;
				m++;
			}
			i++;
		}
		for (i = m - 1; i >= 0; i--)	cout << factorial[i];
		cout << endl;
	}
	return 0;
}