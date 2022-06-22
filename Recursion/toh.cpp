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
	//for getting input from input1.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output1.txt
	freopen("output.txt", "w", stdout);
#endif
}

void toh(int n, char s, char d, char h)
{
	if (n == 1)
	{
		cout << "Move disk " << n << " from " << s << " to " << d << endl;
		return;
	}
	toh(n - 1, s, h, d);
	cout << "Move disk " << n << " from " << s << " to " << d << endl;
	toh(n - 1, h, d, s);
}


int toh(int n, char source, char destination, char helper)
{
	if (n == 1)
	{
		cout << "Move " << n << "th disk from " << source << " to " << destination << endl;
		return 1;
	}

	int count1 = toh(n - 1, source, helper, destination);
	cout << "Move " << n << "th disk from " << source << " to " << destination << endl;
	int count2 = toh(n - 1, helper, destination, source);
	return count1 + count2 + 1;
}

int main()
{
	starter();
	int n;
	cin >> n;
	toh(n, 's', 'd', 'h');
	return 0;
}
