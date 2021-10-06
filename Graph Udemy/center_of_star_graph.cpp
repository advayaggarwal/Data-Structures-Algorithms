#include
using namespace std;

int findCenter(vector&gt; edges)
{
	int n = edges.size();
	unordered_mapm;

	for (int i = 0; i & lt; n; i++)
	{
		int u = edges[i][0], v = edges[i][1];
		m[u]++;
		m[v]++;
	}

	int total_nodes = m.size();

	for (auto p : m)
	{
		if (p.second == total_nodes - 1)	return p.first;
	}

	return -1;
}