//Top Down DP
//Time complexity - O(N*sqrt(N))
//Space complexity - O(N)
class Solution {
public:
    bool winnerSquareGame(int n)
    {
        vector<int>grundy(n + 1, -1);

        return calculateGrundy(n, grundy);
    }

    int calculateGrundy(int n, vector<int> &grundy)
    {
        if (n == 0) return grundy[n] = 0;
        if (grundy[n] != -1)    return grundy[n];

        for (int i = 1; i * i <= n; i++)
        {
            //if I can give any losing position to other player, then this is the winning position for me
            if (!calculateGrundy(n - (i * i), grundy))
            {
                return grundy[n] = 1;
            }
        }

        return grundy[n] = 0;
    }
};

//Bottom UP DP
//Time complexity - O(N*sqrt(N))
//Space complexity - O(N)
class Solution {
public:
    bool winnerSquareGame(int n)
    {
        vector<bool>grundy(n + 1, false);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j * j <= i; j++)
            {
                if (grundy[i - (j * j)] == false) //I can impose losing position to my opponent, hence winning position for me
                {
                    grundy[i] = true;
                    break;
                }
            }
        }

        return grundy[n];
    }
};