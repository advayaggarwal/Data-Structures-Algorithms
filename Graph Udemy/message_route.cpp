#include <bits/stdc++.h>
using namespace std;

int bfs(int source, int n, vector<int>adj[])
{
    vector<bool>visited(n + 1, false);
    vector<int>dis(n + 1, -1);
    queue<int>q;

    q.push(source);
    visited[source] = true;
    dis[source] = 0;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int nbr : adj[node])
        {
            if (!visited[nbr])
            {
                q.push(nbr);
                visited[nbr] = true;
                dis[nbr] = dis[node] + 1;
            }
        }
    }

    return dis[n] + 1;
}

int messageRoute(int n, vector<vector<int>>edges)
{
    vector<int>adj[n + 1];

    int m = edges.size();

    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return bfs(1, n, adj);
}