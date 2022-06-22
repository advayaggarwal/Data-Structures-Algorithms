/*
Checking each bit

Intution is to just count the number of 1s in the bit representation for each element of given array.
Therefore, the highest number of 1s that have been counted at a given bit for the entire array becomes the answer
*/
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int largestCombination(vector<int>& candidates)
    {
        int n = candidates.size();
        if (n == 1)  return 1;

        vector<int>freqOf1(31);

        for (int i = 0; i < n; i++)
        {
            for (int bit = 0; bit < 31; bit++)
            {
                if (candidates[i] & (1 << bit))    freqOf1[bit]++;
            }
        }

        int ans = 0;

        for (int i = 30; i >= 0; i--)
        {
            ans = max(ans, freqOf1[i]);
        }

        return ans;
    }
};

//Time complexity - O(n)
//Space complexity - O(1)
int largestCombination(vector<int>& A) {
    int res = 0, cur = 0;
    for (int i = 1; i <= 10000000; i <<= 1) {
        cur = 0;
        for (int& a : A)
            if (a & i)
                cur++;
        res = max(res, cur);
    }
    return res;
}