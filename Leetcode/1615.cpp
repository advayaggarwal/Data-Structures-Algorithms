//Time complexity - O(n^4)
//Space complexity - O(1)
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int count = 0;
                for (auto &v : roads)
                {
                    if (v[0] == i or v[0] == j or v[1] == i or v[1] == j)    count++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};

//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads)
    {
        int ans = 0;
        vector<unordered_set<int>>adj(n);
        for (int i = 0; i < roads.size(); i++)
        {
            adj[roads[i][0]].insert(roads[i][1]);
            adj[roads[i][1]].insert(roads[i][0]);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int count = adj[i].size() + adj[j].size();
                if (adj[i].count(j)) count--;
                ans = max(ans, count);
            }
        }

        return ans;
    }
};

//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads)
    {
        int ans = 0;
        vector<vector<bool>>adj(n, vector<bool>(n));
        vector<int>count(n);
        for (int i = 0; i < roads.size(); i++)
        {
            count[roads[i][0]]++;
            count[roads[i][1]]++;

            adj[roads[i][0]][roads[i][1]] = true;
            adj[roads[i][1]][roads[i][0]] = true;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int degree = count[i] + count[j];
                if (adj[i][j]) degree--;
                ans = max(ans, degree);
            }
        }

        return ans;
    }
};