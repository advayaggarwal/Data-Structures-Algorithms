//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int dfs(vector<vector<int>>&stones, int index, vector<bool>&visited, int&n)
    {
        visited[index] = true;
        int result = 0;
        for (int i = 0; i < n; i++)
            if (!visited[i] && (stones[i][0] == stones[index][0] || stones[i][1] == stones[index][1]))
                result += (dfs(stones, i, visited, n) + 1);
        return result;
    }
    int removeStones(vector<vector<int>>&stones)
    {
        int n = stones.size();
        vector<bool>visited(n, 0);
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i]) {continue;}
            result += dfs(stones, i, visited, n);
        }

        return result;
    }
};

//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int removeStones(vector<vector<int>>& stones)
    {
        int n = stones.size();
        vector<int>leader(n, -1), rank(n, 1);

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1])
                {
                    int l1 = find(i, leader), l2 = find(j, leader);
                    if (l1 != l2)    Union(i, j, leader, rank);
                }
            }
        }

        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (leader[i] == -1) count++;
        }

        return n - count;
    }

    int find(int x, vector<int>&leader)
    {
        if (leader[x] == -1) return x;
        return leader[x] = find(leader[x], leader);
    }

    void Union(int x, int y, vector<int>&leader, vector<int>&rank)
    {
        int l1 = find(x, leader), l2 = find(y, leader);
        if (l1 != l2)
        {
            if (rank[l1] < rank[l2]) leader[l1] = l2;
            else if (rank[l2] < rank[l1])    leader[l2] = l1;
            else
            {
                leader[l1] = l2;
                rank[l2]++;
            }
        }
    }
};