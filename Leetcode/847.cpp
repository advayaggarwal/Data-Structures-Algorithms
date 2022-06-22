class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph)
    {
        if (graph.size() <= 1) return 0;

        int n = graph.size();
        int final_state = (1 << n) - 1; //all visited 1111...1

        queue<pair<int, int>>q; //{node, visited mask};
        set<pair<int, int>>visited; //{node, visited mask};
        //Adding all nodes initially as we can start from anywhere
        for (int i = 0; i < n; i++)
        {
            q.push({i, 1 << i}); //eg i = 2, n=4, visited mask = 0100
            visited.insert({i, 1 << i});
        }

        int shortestPath = 0;
        while (!q.empty())
        {
            int sz = q.size();
            shortestPath++;
            while (sz--)
            {
                auto p = q.front();
                q.pop();
                int visitedState = p.second;
                for (int nbr : graph[p.first])
                {
                    int newVisitedState = visitedState | (1 << nbr);
                    if (newVisitedState == final_state)  return shortestPath;
                    if (!visited.count({nbr, newVisitedState}))
                    {
                        q.push({nbr, newVisitedState});
                        visited.insert({nbr, newVisitedState});
                    }
                }
            }
        }

        return shortestPath;
    }
};