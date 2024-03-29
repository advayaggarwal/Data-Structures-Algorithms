//Time complexity - O(nlogn)
//Space complexity - O(1)
class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int i = 0, j = tokens.size() - 1, score = 0, maxScore = 0;

        while (i <= j)
        {
            if (tokens[i] <= power)
            {
                score++;
                maxScore = max(maxScore, score);
                power -= tokens[i++];
            }

            else if (score > 0)
            {
                score--;
                power += tokens[j--];
            }

            else break;
        }

        return maxScore;
    }
};