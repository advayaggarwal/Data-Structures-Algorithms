//Apply DFS from room 0, if all visited return true, else return false
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        int n = rooms.size();

        vector<bool>visited(n, false);

        int visited_count = 0;

        dfs(0, visited, rooms, visited_count);

        return visited_count == n;
    }

    void dfs(int room, vector<bool>&visited, vector<vector<int>>& rooms, int &visited_count)
    {
        visited[room] = true;
        visited_count++;

        for (int nbr : rooms[room])
        {
            if (!visited[nbr])   dfs(nbr, visited, rooms, visited_count);
        }
    }
};