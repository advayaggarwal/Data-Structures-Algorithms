//Time complexity - O(n+m)
//Space complexity - O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        else
        {
            int n = matrix.size(), m = matrix[0].size();
            int i = 0, j = m - 1;
            while (i < n && j >= 0)
            {
                if (matrix[i][j] == target)    return true;
                else if (matrix[i][j] > target)    j--;
                else i++;
            }
            return false;
        }
    }
};

//As the first integer of each row is greater than the last integer of the previous row.
//therefore we can apply binary search assuming whole matrix as one array
//Time complexity - O(log(n*m)) => O(log n + log m)
//Space complexity - O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n = matrix.size(), m = matrix[0].size();

        int start = 0, end = n * m - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (matrix[mid / m][mid % m] == target)  return true;

            else if (matrix[mid / m][mid % m] < target)  start = mid + 1;

            else end = mid - 1;
        }

        return false;
    }
};