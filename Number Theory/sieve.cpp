#include<bits/stdc++.h>
using namespace std;

vector<int> primes;
void sieve()
{
	vector<bool> prime(90000001,true);
	int i,j;
	prime[0] = prime[1] = false;
	for(i=2; i*i<=90000000; i++)
	{
		if(prime[i] == true)
		{
			for(j= i*i; j<=90000000; j+=i)
			{
				prime[j] = false;
			}	
		}
	} 
	for(i=2; i<=90000000; i++)
	{
		if(prime[i]==true)	primes.push_back(i);
	}
}


int main()
{
	sieve();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<primes[n-1]<<endl;
	}
	return 0;
}
