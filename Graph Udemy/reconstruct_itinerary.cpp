#include<bits/stdc++.h>
using namespace std;

void dfs(string source, unordered_map<string, multiset<string>>&m, vector<string>&ans)
{
	while (m[source].size() > 0)
	{
		auto it = m[source].begin();
		string nbr = *it;

		m[source].erase(it);

		dfs(nbr, m, ans);
	}

	ans.push_back(source);
}

vector<string> findItinerary(vector<vector<string>> tickets)
{
	unordered_map<string, multiset<string>>m;

	for (int i = 0; i < tickets.size(); i++)
	{
		string u = tickets[i][0];
		string v = tickets[i][1];

		m[u].insert(v);
	}

	vector<string>ans;

	dfs("JFK", m, ans);

	reverse(ans.begin(), ans.end());

	return ans;
}