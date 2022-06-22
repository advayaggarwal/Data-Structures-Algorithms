//Binary Search on ans
//Time complexity - O(n*logm), where n is the length of array and m is the maximum element of that array
//Space complexity - O(1)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int n = piles.size();
        int lo = 1, hi = *max_element(piles.begin(), piles.end());
        int ans;
        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if (isPossible(piles, mid, h))
            {
                ans = mid;
                hi = mid - 1;
            }

            else lo = mid + 1;
        }

        return ans;
    }

    bool isPossible(vector<int>&piles, int k, int h)
    {
        int n = piles.size();
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += (piles[i] + k - 1) / k;
        }

        return count <= h;
    }
};