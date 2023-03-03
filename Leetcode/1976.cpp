//Dijkstra
//Time complexity - O(ElogV)
//Space complexity - O(V + E)
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads)
    {
        vector<long long>dist(n, LONG_MAX), ways(n, 0);
        vector<pair<int, int>>adj[n];
        for (auto v : roads)
        {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }
        dist[0] = 0, ways[0] = 1;
        int mod = 1e9 + 7;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>>minHeap;
        minHeap.push({0, 0});

        while (!minHeap.empty())
        {
            long long costTillNow = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();

            for (auto nbrPair : adj[node])
            {
                int edgeWeight = nbrPair.second;
                int nbr = nbrPair.first;

                if (costTillNow + edgeWeight < dist[nbr])
                {
                    dist[nbr] = costTillNow + edgeWeight;
                    ways[nbr] = (ways[node]);
                    minHeap.push({dist[nbr], nbr});
                }

                else if (costTillNow + edgeWeight == dist[nbr])
                {
                    ways[nbr] = (ways[nbr] % mod + ways[node] % mod) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};