//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income)
    {
        long double ans = 0;
        int n = brackets.size(), last = 0;
        for (int i = 0; i < n; i++)
        {
            if (last > income)   break;
            int upper = brackets[i][0];
            int percent = brackets[i][1];
            if (upper >= income)    upper = min(upper, income);
            ans += ((upper - last) * 1LL * percent) / 100.0;
            last = upper;
        }

        return ans;
    }
};