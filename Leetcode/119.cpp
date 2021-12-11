//Time complexity - O(n^2)
//Space complexity - O(n^2)
class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<vector<int>>temp(rowIndex + 1);

        for (int i = 0; i <= rowIndex; i++)
        {
            temp[i].resize(i + 1);
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 or j == i)  temp[i][j] = 1;

                else    temp[i][j] = temp[i - 1][j - 1] + temp[i - 1][j];
            }
        }

        return temp[rowIndex];
    }
};

//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int>prev;
        vector<int>curr;

        for (int i = 0; i <= rowIndex; i++)
        {
            curr.resize(i + 1);
            for (int j = 0; j <= i; j++)
            {
                if (j == 0 or i == j)    curr[j] = 1;
                else curr[j] = prev[j - 1] + prev[j];
            }

            prev = curr;
        }

        return curr;
    }
};

//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int>res(rowIndex + 1, 0);
        res[0] = 1;

        for (int i = 1; i <= rowIndex; i++)
        {
            for (int j = i; j >= 1; j--)
            {
                res[j] = res[j - 1] + res[j];
            }
        }

        return res;
    }
};