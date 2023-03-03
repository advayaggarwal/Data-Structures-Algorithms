//Cycle detection in Directed Graph
//Time complexity - O(V+E)
//Space complexity - O(V)

/*

All the nodes which are a part of cycle will not be a safe node and all the nodes connected to cycle also will not be a safe node
If we find cycle in directed graph using DFS, for the nodes which are a part of cycle or can lead to a cycle
will always be marked as true in pathVisited.

*/

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

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int n = graph.size();
        vector<bool>visited(n), pathVisited(n);
        for (int i = 0; i < n; i++)
        {
            if (!visited[i]) dfs(i, visited, pathVisited, graph);
        }

        vector<int>res;
        for (int i = 0; i < n; i++)
        {
            if (!pathVisited[i]) res.push_back(i);
        }
        return res;
    }

    bool dfs(int i, vector<bool>&visited, vector<bool>&pathVisited, vector<vector<int>>&graph)
    {
        visited[i] = true;
        pathVisited[i] = true;

        for (int nbr : graph[i])
        {
            if (!visited[nbr])
            {
                if (dfs(nbr, visited, pathVisited, graph))   return true;
            }

            else if (pathVisited[nbr])   return true;
        }

        pathVisited[i] = false;
        return false;
    }
};