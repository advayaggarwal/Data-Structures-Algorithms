class Solution {
public:

    int row;
    int col;

    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        vector<vector<bool>>visited(row, vector<bool>(col, false));
        int count  = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    DFS(grid, i , j, visited);
                    count++;
                }
            }
        }

        return count;
    }


    void DFS(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited)
    {
        int rd[4] = { -1, 0, 0, 1}; //{Up, left, right, down}
        int cd[4] = {0, -1, 1, 0};
        visited[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            if (isSafe(grid, i + rd[k], j + cd[k], visited))
            {
                DFS(grid, i + rd[k], j + cd[k], visited);
            }
        }
    }

    bool isSafe(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited)
    {
        return (i >= 0) && (i < row) && (j >= 0) && (j < col) && grid[i][j] == '1' && !visited[i][j] ;
    }

};




class Solution {
public:

    int row;
    int col;

    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        vector<vector<bool>>visited(row, vector<bool>(col, false));
        int count  = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    DFS(grid, i , j, visited);
                    count++;
                }
            }
        }

        return count;
    }


    void DFS(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited)
    {
        visited[i][j] = true;

        if (isSafe(grid, i - 1, j, visited))    DFS(grid, i - 1, j, visited);
        if (isSafe(grid, i, j - 1, visited))    DFS(grid, i, j - 1, visited);
        if (isSafe(grid, i + 1, j, visited))    DFS(grid, i + 1, j, visited);
        if (isSafe(grid, i, j + 1, visited))    DFS(grid, i, j + 1, visited);

    }

    bool isSafe(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited)
    {
        return (i >= 0) && (i < row) && (j >= 0) && (j < col) && grid[i][j] == '1' && !visited[i][j] ;
    }

};