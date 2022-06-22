//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms)
    {
        vector<vector<int>>freq(7, vector<int>(2));
        vector<int>count(7);
        int n = tops.size();
        for (int i = 0; i < n; i++)
        {
            freq[tops[i]][0]++;
            freq[bottoms[i]][1]++;
            count[tops[i]]++;
            if (tops[i] != bottoms[i])   count[bottoms[i]]++;
        }

        int ans = INT_MAX;

        for (int i = 1; i <= 6; i++)
        {
            if (count[i] == n)
            {
                ans = min(ans, min(n - freq[i][0], n - freq[i][1]));
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

//Same logic, different code
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B)
    {
        vector<int> countA(7), countB(7), same(7);
        int n = A.size();
        for (int i = 0; i < n; i++)
        {
            countA[A[i]]++;
            countB[B[i]]++;
            if (A[i] == B[i])   same[A[i]]++;
        }

        int ans = INT_MAX;

        for (int i = 1; i <= 6; i++)
        {
            if (countA[i] + countB[i] - same[i] == n)
            {
                ans = min(ans, min(countA[i], countB[i]) - same[i]);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};