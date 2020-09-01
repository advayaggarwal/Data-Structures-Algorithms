#include<bits/stdc++.h>
using namespace std;


//binary exponentiation -> eg. 3^4 = (3^2)*(3^2) then 3^2 = 3*3 i.e. exponentiation by squaring
int power(int a, int b, int p)
{
	int result = 1;
	while (b)
	{
		if (b % 2) result = (result * a) % p; //if we add %p result would be in range of 0 to p-1 otherwise result will be a^p-2
		a = (a * a) % p;
		b /= 2;
	}
	return result;
}


//fermat's little theorem -> modulo inverse of a modulo p is a^(p-2), only works when p is prime
int inverse(int a, int p)
{
	return power(a, p - 2, p);
}



int main()
{
#ifndef ONLINE_JUDGE
	//for getting input from input1.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output1.txt
	freopen("output.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, p;
	cin >> a >> p;
	int ans = inverse(a, p);
	cout << ans;

	return 0;
}