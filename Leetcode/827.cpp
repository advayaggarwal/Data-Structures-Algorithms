//Time complexity - O(n^2)
class DSU {
public:
    vector<int>rank, leader, size;
    DSU(int n)
    {
        rank = vector<int>(n + 1, 1);
        leader = vector<int>(n + 1, -1);
        size = vector<int>(n + 1, 1);
    }
    int findLeader(int x)
    {
        if (leader[x] == -1) return x;
        return leader[x] = findLeader(leader[x]);
    }
    void unionByRank(int x, int y)
    {
        int leader1 = findLeader(x);
        int leader2 = findLeader(y);

        if (leader1 == leader2)  return;

        if (rank[leader1] < rank[leader2])   leader[leader1] = leader2;
        else if (rank[leader1] > rank[leader2])  leader[leader2] = leader1;
        else
        {
            leader[leader2] = leader1;
            rank[leader1]++;
        }
    }
    void unionBySize(int x, int y)
    {
        int leader1 = findLeader(x);
        int leader2 = findLeader(y);

        if (leader1 == leader2)  return;

        if (size[leader1] > size[leader2])
        {
            leader[leader2] = leader1;
            size[leader1] += size[leader2];
        }
        else
        {
            leader[leader1] = leader2;
            size[leader2] += size[leader1];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid)
    {
        int n = grid.size();
        DSU dsu(n * n);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0) continue;

                int dx[4] = { -1, 1, 0, 0};
                int dy[4] = {0, 0, 1, -1};

                for (int k = 0; k < 4; k++)
                {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1)
                    {
                        int nodeNo = i * n + j, newNodeNo = x * n + y;
                        dsu.unionBySize(nodeNo, newNodeNo);
                    }
                }
            }
        }

        int ans = 0;
        //try to convert every 0 to 1
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1) continue;

                int dx[4] = { -1, 1, 0, 0};
                int dy[4] = {0, 0, 1, -1};
                unordered_set<int>components;
                for (int k = 0; k < 4; k++)
                {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 1)
                    {
                        int newNodeNo = x * n + y;
                        components.insert(dsu.findLeader(newNodeNo));
                    }
                }

                int size = 1;
                for (auto it : components)   size += dsu.size[it];

                ans = max(ans, size);
            }
        }

        for (int cellNo = 0; cellNo < n * n; cellNo++)
        {
            ans = max(ans, dsu.size[dsu.findLeader(cellNo)]);
        }

        return ans;
    }
};