class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {

        if (magazine.size() < ransomNote.size()) return false;

        vector<int>freq(26, 0);

        for (char ch : magazine) freq[ch - 'a']++;

        int n = ransomNote.size();
        for (int i = 0; i < n; i++)
        {
            if (freq[ransomNote[i] - 'a'] <= 0 )    return false;

            freq[ransomNote[i] - 'a']--;
        }

        return true;
    }
};