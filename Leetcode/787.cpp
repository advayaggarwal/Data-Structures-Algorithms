//Queue
//Time complexity - O(E+V)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<pair<int, int>>adj[n]; //{node, cost}
        for (auto f : flights)   adj[f[0]].push_back({f[1], f[2]});
        vector<int>dist(n, INT_MAX);
        dist[src] = 0;
        queue<pair<int, pair<int, int>>>q; //{stops, {node, cost}}
        q.push({0, {src, 0}});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first, node = it.second.first, cost = it.second.second;
            if (stops > k)   continue;
            for (auto iter : adj[node])
            {
                int adjNode = iter.first;
                int edgeWeight = iter.second;
                if (cost + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = cost + edgeWeight;
                    q.push({stops + 1, {adjNode, dist[adjNode]}});
                }
            }
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};

//Bellman Ford
//Time complexity - O(k*E)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<int>dist(n + 1, INT_MAX);
        dist[src] = 0;

        for (int i = 0; i <= k; i++)
        {
            vector<int>temp(dist);
            for (auto edge : flights)
            {
                int u = edge[0], v = edge[1], w = edge[2];
                if (dist[u] != INT_MAX && dist[u] + w < temp[v])   temp[v] = dist[u] + w;
            }
            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};