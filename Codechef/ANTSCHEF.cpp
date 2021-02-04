/*
	AUTHOR:			ADVAY AGGARWAL
	INSTITUTION:	IIIT DHARWAD
*/
#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long
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
		int l;
		cin >> l;
		vector<vi>left(l);
		vector<vi> right(l);
		map<int, vector<pair<int, int>>> mp; //(distance=d, for all ants at distance d (line_id, direction))
		for (int i = 0; i < l; i++)
		{
			int n;
			cin >> n;
			for (int j = 0; j < n; j++)
			{
				int x;
				cin >> x;
				if (x > 0)
				{
					right[i].push_back(x);
					mp[x].push_back({i, 1}); //1 for right, -1 for left
				}
				else
				{
					left[i].push_back(abs(x));
					mp[abs(x)].push_back({i, -1});
				}
			}
			sort(left[i].begin(), left[i].end());
			sort(right[i].begin(), right[i].end());
		}
		ll sum = 0;
		for (auto itr = mp.begin(); itr != mp.end(); itr++)
		{
			int pt = itr->first;
			vector<pair<int, int>>v = itr->second;
			if (v.size() == 1)
			{
				int id = v[0].first;
				int dir = v[0].second;
				if (dir == 1)
				{
					int length = left[id].size();
					int index = lower_bound(left[id].begin(), left[id].end(), pt) - left[id].begin();
					if (index < length)
					{
						sum += length - index;
					}
				}
				else
				{
					int length = right[id].size();
					int index = lower_bound(right[id].begin(), right[id].end(), pt) - right[id].begin();
					if (index < length)
					{
						sum += length - index;
					}
				}
			}
			else
			{
				sum += 1;
				for (int i = 0; i < v.size(); i++)
				{
					int id = v[i].first;
					int dir = v[i].second;
					if (dir == 1)
					{
						int length = right[id].size();
						int index = lower_bound(right[id].begin(), right[id].end(), pt) - right[id].begin();
						sum += length - index - 1;
					}
					else
					{
						int length = left[id].size();
						int index = lower_bound(left[id].begin(), left[id].end(), pt) - left[id].begin();
						sum += length - index - 1;
					}
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}