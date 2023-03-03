//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int longestSubsequence(string s, int k)
    {
        int n = s.size(), ans = 0;
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0') ans++;
            else if (i < 31 && (1 << i) <= k)
            {
                ans++;
                k -= 1 << i;
            }
        }

        return ans;
    }
};