class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;

        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0, left = 0, bottom = m - 1, right = n - 1;
        int dir = 0;
        // 0 means left to right, 1 means top to bottom
        //2 means right to left, 3 means bottom to top
        while (top <= bottom && left <= right)
        {
            if (dir == 0)
            {
                for (int i = left; i <= right; i++)  res.push_back(matrix[top][i]);
                top++;
            }

            else if (dir == 1)
            {
                for (int i = top; i <= bottom; i++)  res.push_back(matrix[i][right]);
                right--;
            }

            else if (dir == 2)
            {
                for (int i = right; i >= left; i--)  res.push_back(matrix[bottom][i]);
                bottom--;
            }

            else if (dir == 3)
            {
                for (int i = bottom; i >= top; i--)  res.push_back(matrix[i][left]);
                left++;
            }

            dir = (dir + 1) % 4;
        }


        return res;
    }

};