//Time complexity - O(M*N)
//Space complexity - O(M+N)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>>m;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0) m.push_back({i, j});
            }
        }

        for (auto &e : m)
        {
            for (int i = 0; i < cols; i++)
            {
                matrix[e.first][i] = 0;
            }

            for (int i = 0; i < rows; i++)
            {
                matrix[i][e.second] = 0;
            }
        }

    }
};


//Time complexity - O(M*N)
//Space complexity - O(1)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool isCol = false;

        // Since first cell for both first row and first column is the same i.e. matrix[0][0]
        // We can use an additional variable for either the first row/column.
        // For this solution we are using an additional variable for the first column
        // and using matrix[0][0] for the first row.
        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][0] == 0) isCol = true;
            for (int j = 1; j < cols; j++)
            {

                // If an element is zero, we set the first element of the corresponding row and column to 0
                if (matrix[i][j] == 0)
                {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // Iterate over the array from the end and using the first row and first column, update the elements.
        //We are iterating from the end because we don't want to lose the elements(the values for which column we have to set 0) stored in the first row
        for (int i = rows - 1; i >= 0; i--)
        {
            for (int j = cols - 1; j >= 1; j--)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)  matrix[i][j] = 0;
            }

            // See if the first column needs to be set to zero as well
            if (isCol)
            {
                matrix[i][0] = 0;
            }

        }





    }
};