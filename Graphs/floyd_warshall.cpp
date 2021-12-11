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
#define vvi vector<vi>

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

//Time complexity - O(n^3)
//Space complexity - O(n^2)
vector<vector<int>>floyd_warshall(vector<vector<int>>&graph)
{
	vector<vector<int>>dist(graph);
	int n = graph.size();

	//Phases, in kth phase we include vertices (1,2,...k) as intermediate vertices
	for (int k = 0; k < n; k++)
	{
		//Iterate over 2D matrix graph
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				//if vertex k is included, and can we minimise the dist?
				if (dist[i][j] > long(dist[i][k]) + long(dist[k][j])) //to avoid integer overflow
				{
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}

	return dist;
}

int main()
{
	starter();

	int n;
	cin >> n;

	vector<vector<int>>graph(n, vector<int>(n));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
	}

	vector<vector<int>>dist = floyd_warshall(graph);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}