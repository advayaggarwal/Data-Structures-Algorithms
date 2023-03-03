//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int candy(vector<int>& ratings)
    {
        int n = ratings.size();
        vector<int>val(n, 1);

        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1])   val[i] = val[i - 1] + 1;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1] && val[i + 1] >= val[i])   val[i] = val[i + 1] + 1;
        }

        int ans = 0;
        for (int x : val)    ans += x;
        return ans;
    }
};