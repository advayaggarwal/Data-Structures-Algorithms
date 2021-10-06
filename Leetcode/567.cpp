//Sliding Window
//Time complexity - O(n)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        vector<int>freq(26, 0);
        int n1 = s1.size(), n2 = s2.size();

        for (int i = 0; i < n1; i++) freq[s1[i] - 'a']++;

        int start = 0, end = 0;
        while (end < n2)
        {
            freq[s2[end] - 'a']--;

            while (freq[s2[end] - 'a'] < 0)
            {
                freq[s2[start] - 'a']++;
                start++;
            }

            if (end - start + 1 == n1)   return true; //all chars have freq 0, so if no of chars in window is equal to total chars in s1, return true

            end++;
        }

        return false;
    }
};