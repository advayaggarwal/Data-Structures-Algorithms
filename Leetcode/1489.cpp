//Time complexity - O(e^2), where e is #edges
//Space complexity - O(n), where n is #vertices
class Solution {
public:

    void init(int n, vector<int>&leader, vector<int>&rank)
    {
        for (int i = 0; i < n; i++)
        {
            leader[i] = -1;
            rank[i] = 1;
        }
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
                leader[l2] = l1;
                rank[l1]++;
            }
        }
    }

    int MST(vector<vector<int>>& edges, int avoid, vector<int>&leader, vector<int>&rank)
    {
        int cost = 0;
        int n = leader.size();

        for (auto e : edges)
        {
            int id = e[3];
            if (id == avoid) continue;

            int u = e[0];
            int v = e[1];
            int weight = e[2];

            int l1 = find(u, leader);
            int l2 = find(v, leader);

            if (l1 != l2)
            {
                Union(u, v, leader, rank);
                cost += weight;
            }
        }

        for (int i = 1; i < n; i++)
        {
            if (find(i, leader) != find(0, leader))  return INT_MAX; //graph not connected, has more than 1 component
            //so if cost is INFINITY, it will get included in critical edges
        }

        return cost;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges)
    {
        vector<int>leader(n, -1), rank(n, 1);

        for (int i = 0; i < edges.size(); i++)   edges[i].push_back(i);

        sort(edges.begin(), edges.end(), [](vector<int>&a, vector<int>&b) {
            return a[2] < b[2];
        });

        int minCost = MST(edges, -1, leader, rank);

        vector<int>critical, pseudo_critical;

        for (auto e : edges)
        {
            init(n, leader, rank);

            int cost = MST(edges, e[3], leader, rank);

            if (cost > minCost)  critical.push_back(e[3]); //without including this edge cost is increasing, so it's critical

            else //include it and then find the cost
            {
                init(n, leader, rank);
                Union(e[0], e[1], leader, rank);
                cost = e[2];

                cost += MST(edges, e[3], leader, rank);

                if (cost == minCost) pseudo_critical.push_back(e[3]);
            }
        }

        return {critical, pseudo_critical};
    }
};