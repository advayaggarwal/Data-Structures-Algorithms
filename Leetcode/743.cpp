//Dijkstra's Algorithm using Set
//Time complexity - O(V + ElogV)
//Space complexity - O(V+E)
#define pii pair<int,int>
#define vi vector<int>
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<pii>adj[n + 1];
        for (int i = 0; i < times.size(); i++)
        {
            int u = times[i][0], v = times[i][1], w = times[i][2];
            adj[u].push_back({v, w});
        }

        vi distance(n + 1, INT_MAX);
        dijkstra(k, adj, distance);

        int ans = INT_MIN;
        for (int i = 1; i <= n; i++)
        {
            if (distance[i] == INT_MAX) return -1;
            ans = max(ans, distance[i]);
        }

        return ans;
    }

    void dijkstra(int src, vector<pii>adj[], vi &distance)
    {
        distance[src] = 0;
        set<pii>s; //{distance, node}
        s.insert({0, src});

        while (!s.empty())
        {
            auto it = s.begin();
            int node = it->second;
            int dis_till_now = it->first;
            s.erase(it);

            for (auto n : adj[node])
            {
                int nbr = n.first;
                int w = n.second;

                if (dis_till_now + w < distance[nbr])
                {
                    s.erase({distance[nbr], nbr});
                    distance[nbr] = dis_till_now + w;
                    s.insert({distance[nbr], nbr});
                }
            }
        }
    }
};

//Dijkstra's Algorithm using Priority Queue
//Time complexity - O(V + ElogV)
//Space complexity - O(V+E)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<pair<int, int>>adj[n + 1];

        for (auto &v : times)
        {
            adj[v[0]].push_back({v[1], v[2]});
        }

        vector<int>dist(n + 1, INT_MAX);
        dist[k] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, k});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int distTillNow = pq.top().first;
            pq.pop();

            for (auto &p : adj[node])
            {
                if (p.second + distTillNow < dist[p.first])
                {
                    dist[p.first] = p.second + distTillNow;
                    pq.push({dist[p.first], p.first});
                }
            }
        }

        int ans = 0;

        for (int i = 1; i <= n; i++) ans = max(ans, dist[i]);
        return ans == INT_MAX ? -1 : ans;
    }
};