/*
	AUTHOR:			ADVAY AGGARWAL
*/

/* Impatient with actions, patient with results. */

#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define int 	long long int
#define vi vector<int>
#define vvi vector<vi>
#define setbits(x)      __builtin_popcountll(x)
#define endl "\n"
#define pii pair<int,int>
#define vpi vector<pii>
#define F first
#define S second
#define pb push_back
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)


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

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 1000005;

int pr_sum[N]; //total prime factors of i, e.g. 20 -> 2 * 2 * 5, pr_sum[20] = 3;

void sieve()
{
	vector<bool>isPrime(N, true);
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i < N; i++)
	{
		if (isPrime[i])
		{
			pr_sum[i] = 1;

			for (int j = 2 * i; j < N; j += i)
			{
				isPrime[j] = false;
				int jj = j;

				while (jj % i == 0)
				{
					jj /= i;
					pr_sum[j]++;
				}
			}
		}
	}
}

void starter()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

/*
Now think carefully such a way that , if we reduce a number X to its divisor Y.
Then It eliminates some of its prime-factors .It can be turned into our standard nim game where prime factors
of the number are considered to be number of stones of that particular pile. So every time when we made it
equal to its divisor which in turn eliminate one or more stones from that pile .

*/

void solve()
{
	int n;
	cin >> n;

	int nimSum = 0;
	for (int i = 0; i < n; i++)
	{
		int h;
		cin >> h;

		nimSum ^= pr_sum[h];
	}

	if (nimSum)	cout << 1 << endl;
	else cout << 2 << endl;
}

int32_t main()
{
	starter();
	clock_t z = clock();

	int t = 1;
	cin >> t;

	sieve();
	while (t--)	solve();

	cerr << "Run time: " << ((double)(clock() - z) / CLOCKS_PER_SEC) << " ";
	return 0;
}