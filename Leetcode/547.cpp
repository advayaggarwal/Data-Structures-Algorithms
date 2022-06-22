//Using DFS
//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        vector<bool>visited(n, false);

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, n, isConnected, visited);
                count++;
            }
        }

        return count;
    }

    void dfs(int node, int n, vector<vector<int>>& isConnected, vector<bool>&visited)
    {
        visited[node] = true;
        for (int j = 0; j < n; j++)
        {
            if (isConnected[node][j] == 1 && !visited[j])
            {
                dfs(j, n, isConnected, visited);
            }
        }
    }
};

//Using DSU
//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n = isConnected.size();
        vector<int>leader(n, -1);
        vector<int>rank(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)  Union(i, j, leader, rank);
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (leader[i] == -1)   count++;
        }

        return count;
    }

    int find(int x, vector<int>&leader)
    {
        if (leader[x] == -1)   return x;

        return leader[x] = find(leader[x], leader);
    }

    void Union(int x, int y, vector<int>&leader, vector<int>&rank)
    {
        int l1 = find(x, leader);
        int l2 = find(y, leader);

        if (l1 == l2)    return;

        if (rank[l1] < rank[l2]) leader[l1] = l2;
        else if (rank[l1] > rank[l2])    leader[l2] = l1;
        else
        {
            leader[l1] = l2;
            rank[l2]++;
        }
    }
};