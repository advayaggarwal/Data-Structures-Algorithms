//Dijkstra - TLE
//Time complexity - O((V+E)*logV) = O(ElogV)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<pair<int, int>>adj[n];

        for (int i = 0; i < flights.size(); i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            adj[u].push_back({v, wt});
        }

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>minHeap; //cost, node, k

        minHeap.push({0, {src, k}});

        while (!minHeap.empty())
        {
            auto p = minHeap.top();
            minHeap.pop();

            int cost = p.first;
            int node = p.second.first;
            int stops = p.second.second;

            if (node == dst) return cost;

            if (stops >= 0)
            {
                for (auto nbr : adj[node])
                {
                    minHeap.push({cost + nbr.second, {nbr.first, stops - 1}});
                }
            }
        }

        return -1;
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