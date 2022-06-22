//Kruskal's Algorithm
//Time complexity - O((n^2)*logn), computing edges and sorting them, DSU is O(1)
//Space complexity - O(n^2), for storing edges
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points)
    {
        int n = points.size();
        vector<int>leader(n, -1), rank(n, 1);

        vector<pair<int, pair<int, int>>>edges;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int xi = points[i][0];
                int yi = points[i][1];
                int xj = points[j][0];
                int yj = points[j][1];
                int cost = abs(xi - xj) + abs(yi - yj);
                edges.push_back({cost, {i, j}});
            }
        }

        sort(edges.begin(), edges.end());

        int res = 0;
        for (auto &e : edges)
        {
            int u = e.second.first;
            int v = e.second.second;
            int cost = e.first;

            if (find(u, leader) != find(v, leader))
            {
                Union(u, v, leader, rank);
                res += cost;
            }
        }

        return res;
    }

    int find(int x, vector<int>&leader)
    {
        if (leader[x] == -1) return x;

        return leader[x] = find(leader[x], leader);
    }

    void Union(int x, int y, vector<int>&leader, vector<int>&rank)
    {
        int l1 = find(x, leader);
        int l2 = find(y, leader);

        if (l1 != l2)
        {
            if (rank[l1] < rank[l2]) leader[l1] = l2;
            else if (rank[l1] > rank[l2])    leader[l2] = l1;
            else
            {
                leader[l1] = l2;
                rank[l2]++;
            }
        }
    }
};