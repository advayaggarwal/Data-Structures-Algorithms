class Solution {
public:
    int maxCoins(vector<int>& piles) {

        int n = piles.size();
        sort(piles.begin(), piles.end(), greater<int>());

        int ans = 0;
        int i = 1;
        int count = 0;
        while (count < n / 3)
        {
            ans += piles[i];
            i += 2;
            count++;
        }

        return ans;
    }
};