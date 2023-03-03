//Time complexity - O(n + 26*26)
//Space complexity - O(26)
class Solution {
public:
    int minDeletions(string s)
    {
        vector<int>freq(26);
        for (char &c : s) freq[c - 'a']++;
        unordered_set<int>seenFrequencies;

        int ans = 0;

        for (int i = 0; i < 26; i++)
        {
            while (freq[i] && seenFrequencies.count(freq[i]))
            {
                freq[i]--;
                ans++;
            }

            seenFrequencies.insert(freq[i]);
        }

        return ans;
    }
};

//Time complexity - O(n + 26*log26)
//Space complexity - O(26)
class Solution {
public:
    int minDeletions(string s)
    {
        vector<int>freq(26);
        for (char &c : s) freq[c - 'a']++;
        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0, maxAllowed = s.size();

        for (int i = 0; i < 26 && freq[i] > 0; i++)
        {
            if (freq[i] > maxAllowed)
            {
                ans += freq[i] - maxAllowed;
                freq[i] = maxAllowed;
            }

            maxAllowed = max(0, freq[i] - 1);
        }

        return ans;
    }
};