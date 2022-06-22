//Time complexity - O(n)
//Space complexity- O(1)
class Solution {
public:
    char findTheDifference(string s, string t)
    {
        vector<int>freq(26);

        for (int i = 0; i < t.size(); i++)
        {
            freq[t[i] - 'a']++;
        }

        for (int i = 0; i < s.size(); i++)   freq[s[i] - 'a']--;

        for (int i = 0; i < 26; i++) if (freq[i]) return 'a' + i;

        return '\0';
    }
};

//Using Xor property
class Solution {
public:
    char findTheDifference(string s, string t)
    {
        int res = 0;

        for (int i = 0; i < t.size(); i++)   res ^= t[i];
        for (int i = 0; i < s.size(); i++)   res ^= s[i];

        return res; //return type is char and res contains ascii value
    }
};