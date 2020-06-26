#include<bits/stdc++.h>
using namespace std;


//binary exponentiation -> eg. 3^4 = (3^2)*(3^2) then 3^2 = 3*3
int power(int a, int b)
{
	int result = 1;
	while(b)
	{
		if(b%2) result*=a;
		a*=a;
		b/=2;
	}
	return result;
}


//fermat's little theorem -> modulo inverse of a modulo p is a^(p-2) 
int inverse(int a, int p)
{
	return power(a,p-2); 
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
	int a,p;
	cin>>a>>p;
	int ans = inverse(a,p);
	cout<<ans;
	
	return 0;
}