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

int extended_euclid(int a, int b, int& x, int& y)
{
	if (b == 0) // if one no. is zero then gcd is the other no. i.e. we have returned a
	{
		x = 1;  // b=0 and ax+by = gcd(a,b) = a -> x=1 & y=0
		y = 0;
		return a;
	}
	int x1, y1;
	int ans = extended_euclid(b, a % b, x1, y1);
	x = y1; // as gcd(a,b) = gcd(b,a%b) & ax+by=gcd(a,b)=ax1+by1
	y = x1 - y1 * (a / b);
	return ans;

}

int main()
{
	starter();
	int a, b, x, y;
	cin >> a >> b;
	int ans = extended_euclid(a, b, x, y);
	cout << "GCD is " << ans << endl;
	cout << "x is " << x << endl << "y is " << y;
	return 0;
}