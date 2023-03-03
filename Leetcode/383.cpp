//Time complexity - O(m+n), where m is #chars in magazine, and n is #chars in ransomNote
//Space complexity - O(1)
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        vector<int>freq(26);
        for (char c : magazine)  freq[c - 'a']++;
        for (char c : ransomNote)
        {
            freq[c - 'a']--;
            if (freq[c - 'a'] < 0) return false;
        }
        return true;
    }
};