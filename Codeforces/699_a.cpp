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
		int px, py;
		cin >> px >> py;
		string s;
		cin >> s;
		int d[5] = {0};
		//1-L 2-R 3-U 4-D
		for (int i = 0; i < int(s.size()); i++)
		{
			if (s[i] == 'L')	d[1]++;
			else if (s[i] == 'R')	d[2]++;
			else if (s[i] == 'U')	d[3]++;
			else	d[4]++;
		}
		int flagx = px > 0 ? 1 : 0;
		int flagy = py > 0 ? 1 : 0;
		bool ans = false;
		if ((((flagx) && (d[2] >= px)) || ((!flagx) && (d[1] >= (-1 * px)))) && (((flagy) && (d[3] >= py)) || ((!flagy && d[4] >= (-1 * py)))))
		{
			ans = true;
		}

		if (ans)	cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}







