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
		int n;
		cin >> n;
		string s[n];
		map<string, int [26]>m;
		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
			char x = s[i][0];
			s[i][0] = '*';
			m[s[i]][x - 'a'] = 1;
		}

		ll ans = 0;
		ll count1 = 0, count2 = 0;
		for (auto it = m.begin(); it != m.end(); it++)
		{
			for (auto itr = it; itr != m.end(); itr++)
			{
				if (it == itr)	continue;
				count1 = 0;
				count2 = 0;
				for (int i = 0; i < 26; i++)
				{
					if (it->second[i] != itr->second[i])
					{
						if (it->second[i] == 1)	count1++;
						else count2++;
					}
				}
				ans += (count1 * count2);
			}
		}
		cout <<  2 * ans << endl;

	}
	return 0;
}

// int main()
// {
// 	starter();
// 	test_cases(t)
// 	{
// 		int n;
// 		cin >> n;
// 		string s[n];
// 		ll ans = 0;
// 		unordered_map<string, int> Set;
// 		vector<char>v;
// 		for (int i = 0; i < n; i++)
// 		{
// 			cin >> s[i];
// 			Set[s[i]] = i;
// 		}
// 		sort(s, s + n);
// 		for (int i = 0; i < n; i++)
// 		{
// 			v.push_back(s[i][0]);
// 		}
// 		int u[26];
// 		memset(u, -1, sizeof(u));
// 		if (v[0] == v[n - 1])	cout << 0 << endl;
// 		else
// 		{
// 			for (int i = 0; i < n; i++)
// 			{
// 				int x = (v[i] - 'a');
// 				int j;
// 				if (u[x] == -1)
// 				{
// 					j = upper_bound(v.begin(), v.end(), v[i]) - v.begin();
// 					u[x] = j;
// 				}
// 				else  j = u[x];
// 				for (; j < n; j++)
// 				{
// 					string s1 = s[i];
// 					string s2 = s[j];
// 					s1[0] = '*';
// 					s2[0] = '*';
// 					if (s1 == s2)	continue;
// 					else
// 					{
// 						s1[0] = s[j][0];
// 						s2[0] = s[i][0];
// 						if ((Set.find(s1) == Set.end()) && (Set.find(s2) == Set.end()))	ans += 2;
// 					}
// 				}
// 			}
// 			cout << ans << endl;
// 		}
// 	}
// 	return 0;
// }