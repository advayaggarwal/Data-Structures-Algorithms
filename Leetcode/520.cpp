//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    bool detectCapitalUse(string word)
    {
        bool firstCapital = true;
        if (word[0] >= 'a' && word[0] <= 'z') firstCapital = false;

        int n = word.size();
        bool allCapital = true, allNotCapital = true;
        for (int i = 1; i < n; i++)
        {
            if (word[i] >= 'a' && word[i] <= 'z') allCapital = false;

            else allNotCapital = false;
        }

        return (firstCapital && (allCapital or allNotCapital)) or (!firstCapital && allNotCapital);
    }
};