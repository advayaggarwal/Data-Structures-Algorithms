/*
Intuition:
Consider trust as a graph, all pairs are directed edge.
The point with in - degree - out - degree = N - 1 become the judge.

Explanation:
Count the degree, and check at the end.
*/

//Time complexity - O(N+E)
//Space complexity - O(N)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust)
    {
        vector<int>count(n + 1, 0);

        for (int i = 0; i < trust.size(); i++)
        {
            int x = trust[i][0];
            int y = trust[i][1];
            count[x]--;
            count[y]++;
        }

        for (int i = 1; i <= n; i++)
        {
            if (count[i] == n - 1)    return i;
        }

        return -1;
    }
};