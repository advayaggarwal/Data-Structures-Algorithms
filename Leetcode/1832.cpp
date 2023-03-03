//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    bool checkIfPangram(string sentence)
    {
        vector<int>freq(26);
        for (char c : sentence)  freq[c - 'a']++;
        for (int i = 0; i < 26; i++) if (freq[i] == 0)    return false;
        return true;
    }
};