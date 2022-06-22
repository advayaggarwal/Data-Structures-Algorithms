//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int maxPower(string s)
    {
        int ans = 1;
        int n = s.size();
        int count = 1;

        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])  count++;

            else
            {
                ans = max(ans, count);
                count = 1;
            }
        }

        return max(ans, count);
    }
};