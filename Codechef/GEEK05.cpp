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
	const int N = 1e5+7;
	static ll int a[N];
	ll int x = 1;
	for(int i=0; i<N; i++)
	{
	    a[i] = x;
	    x = (x*2)%mod;
	}
	for(int i=1; i<N; i++)
	{
	    for(int j=2*i; j<N; j+=i)
	    {
	        a[j]= (a[j]-a[i]+mod)%mod;
	        //if(a[j]<0)  a[j]+=mod;
	        //a[j] = a[j]%mod;
	    }
	}
	static ll int dp[N];
	dp[0] = a[0];
	for(int i=1; i<N; i++)
	{
	    dp[i]= (dp[i-1]+a[i])%mod;
	}
	
	test_cases(t)
	{
        int l, r;
        cin>>l>>r;
        cout<<(dp[r]-dp[l-1]+mod)%mod<<"\n";
	}
	return 0;
}