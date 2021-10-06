/*
	AUTHOR:			ADVAY AGGARWAL
*/

#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long int
#define test_cases(x)	int x; cin>>x; while(x--)
#define vi vector<int>
#define setbits(x)      __builtin_popcountll(x)
#define endl "\n"
#define pii pair<int,int>


template <typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
	int n = vec.size();
	for (int i = 0; i < n; i++)	in >> vec[i];
	return in;
}

template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
	for (auto &val : vec)	out << val << " ";
	return out;
}

void starter()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

/*
	Given an array you need to count number of triplets with indices (i,j,k) such that the elements at those
	indices are in geometric progression for a given common ratio r and (i < j < k).
*/

//Time complexity - O(N)
void tripletsInGP(vi &v, int r)
{
	int n = v.size();
	unordered_map<ll, ll>left, right;
	//Left -> Number of a/r having index less than i
	//Right -> Number of a*r having index greater than i

	//Init the right map with frequencies , left map = 0;
	for (int i = 0; i < n; i++)
	{
		right[v[i]]++;
		left[v[i]] = 0;
	}

	//Compute by iterating left to right and considering v[i] as middle element a of GP -> a/r, a, a*r
	ll ans = 0;

	for (int i = 0; i < n; i++)
	{
		right[v[i]]--;

		if (v[i] % r == 0)
		{
			ll b = v[i];
			ll a = v[i] / r;
			ll c = v[i] * r;

			ans += left[a] * right[c];
		}

		left[v[i]]++;
	}

	cout << ans;
}

int main()
{
	starter();

	int n, r;
	cin >> n >> r;

	vi v(n);
	cin >> v;

	tripletsInGP(v, r);

	return 0;
}