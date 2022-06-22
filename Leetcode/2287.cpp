//Time complexity - O(m+n), where m is length of s, and n is length of target
//Space complexity - O(1)
class Solution {
public:
    int rearrangeCharacters(string s, string target)
    {
        vector<int>freq1(26), freq2(26);
        for (char c : s)  freq1[c - 'a']++;
        for (char c : target)  freq2[c - 'a']++;

        int ans = INT_MAX;
        for (int i = 0; i < 26; i++)
        {
            if (freq2[i] > 0) ans = min(ans, freq1[i] / freq2[i]);
        }

        return ans;
    }
};