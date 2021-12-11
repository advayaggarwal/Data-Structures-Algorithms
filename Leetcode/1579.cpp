class Solution {
public:
	int find(int x, vector<int>&leader)
	{
		if (leader[x] == -1)	return x;

		return leader[x] = find(leader[x], leader);
	}

	void Union(int x, int y, vector<int>&leader, vector<int>&rank)
	{
		int l1 = find(x, leader);
		int l2 = find(y, leader);

		if (l1 != l2)
		{
			if (rank[l1] < rank[l2])	leader[l1] = l2;
			else if (rank[l1] > rank[l2])	leader[l2] = l1;

			else
			{
				leader[l2] = l1;
				rank[l1]++;
			}
		}
	}

	int maxNumEdgesToRemove(int n, vector<vector<int>>&edges)
	{
		vector<pair<int, int>>type[3];

		for (int i = 0; i < edges.size(); i++)
		{
			int t = edges[i][0];
			int x = edges[i][1], y = edges[i][2];

			type[t - 1].push_back({x, y});
		}

		vector<int>leadera(n + 1, -1), leaderb(n + 1, -1), ranka(n + 1, 1), rankb(n + 1, 1);

		int ans = 0;
		int counta = 1, countb = 1;

		for (int i = 0; i < type[2].size(); i++)
		{
			int x = type[2][i].first;
			int y = type[2][i].second;

			int l1 = find(x, leadera);
			int l2 = find(y, leadera);

			if (l1 == l2)	ans++;
			else
			{
				Union(x, y, leadera, ranka);
				Union(x, y, leaderb, rankb);
				counta++;
				countb++;
			}
		}

		for (int i = 0; i < type[1].size(); i++)
		{
			int x = type[1][i].first;
			int y = type[1][i].second;

			int l1 = find(x, leaderb);
			int l2 = find(y, leaderb);

			if (l1 == l2)	ans++;

			else
			{
				Union(x, y, leaderb, rankb);
				countb++;
			}
		}

		for (int i = 0; i < type[0].size(); i++)
		{
			int x = type[0][i].first;
			int y = type[0][i].second;

			int l1 = find(x, leadera);
			int l2 = find(y, leadera);

			if (l1 == l2)	ans++;

			else
			{
				Union(x, y, leadera, ranka);
				counta++;
			}
		}

		if (counta != n or countb != n)	return -1;

		return ans;
	}

};