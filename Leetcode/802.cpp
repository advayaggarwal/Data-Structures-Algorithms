//Cycle detection in Directed Graph
//Time complexity - O(V+E)
//Space complexity - O(V)

//All the nodes which are a part of cycle will not be a safe node
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<bool>visited(n), dfsVisited(n);
        vector<bool>nodesInCycle(n);

        for (int i = 0; i < n; i++)
        {
            if (!visited[i]) dfs(i, graph, visited, dfsVisited, nodesInCycle);
        }

        vector<int>ans;
        for (int i = 0; i < n; i++)
        {
            if (!nodesInCycle[i])    ans.push_back(i);
        }

        return ans;
    }

    bool dfs(int src, vector<vector<int>>&graph, vector<bool>&visited, vector<bool>&dfsVisited, vector<bool>&nodesInCycle)
    {
        visited[src] = true;
        dfsVisited[src] = true;

        for (int &nbr : graph[src])
        {
            if (!visited[nbr])
            {
                if (dfs(nbr, graph, visited, dfsVisited, nodesInCycle))    return nodesInCycle[src] = true;
            }

            else if (dfsVisited[nbr])    return nodesInCycle[src] = true;
        }

        dfsVisited[src] = false;

        return false;
    }
};