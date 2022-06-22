//Divide & Conquer - Recursion
//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    int longestSubstring(string s, int k)
    {
        int n = s.size();
        return helper(s, 0, n - 1, k);
    }

    int helper(string &s, int start, int end, int k)
    {
        if (start > end) return 0;
        vector<int>freq(26);

        for (int i = start; i <= end; i++)    freq[s[i] - 'a']++;

        for (int mid = start; mid <= end; mid++)
        {
            if (freq[s[mid] - 'a'] >= k)    continue;

            return max(helper(s, start, mid - 1, k), helper(s, mid + 1, end, k));
        }

        return (end - start + 1);
    }
};