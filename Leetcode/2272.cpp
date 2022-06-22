//Kadane's Algorithm
//Time complexity - O(26*26*2*n)
//Space complexity - O(1)
class Solution {
public:
    int largestVariance(string s)
    {
        vector<int>freq(26);
        for (char c : s) freq[c - 'a']++;
        int ans = 0;
        for (char ch1 = 'a'; ch1 <= 'z'; ch1++)
        {
            for (char ch2 = 'a'; ch2 <= 'z'; ch2++)
            {
                if (ch1 == ch2 or freq[ch1 - 'a'] == 0 or freq[ch2 - 'a'] == 0)  continue;

                for (int k = 0; k < 2; k++)
                {
                    int countA = 0, countB = 0;
                    for (char c : s)
                    {
                        if (c == ch1)  countA++;
                        else if (c == ch2) countB++;

                        if (countA < countB) countA = countB = 0;

                        if (countA > 0 && countB > 0)    ans = max(ans, countA - countB);
                    }

                    reverse(s.begin(), s.end());
                }
            }
        }

        return ans;
    }
};