class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>>res(n, vector<int>(n, 0));

        int t = 0, b = n - 1, l = 0, r = n - 1, dir = 0;
        int no = 1;

        while (t <= b && l <= r)
        {
            if (dir == 0)
            {
                for (int i = l; i <= r; i++)
                {
                    res[t][i] = no;
                    no++;
                }
                t++;
            }

            else if (dir == 1)
            {
                for (int i = t; i <= b; i++)
                {
                    res[i][r] = no;
                    no++;
                }
                r--;
            }

            else if (dir == 2)
            {
                for (int i = r; i >= l; i--)
                {
                    res[b][i] = no;
                    no++;
                }
                b--;
            }

            else
            {
                for (int i = b; i >= t; i--)
                {
                    res[i][l] = no;
                    no++;
                }
                l++;
            }

            dir = (dir + 1) % 4;
        }

        return res;
    }
};