class Solution {
public:
    bool makesquare(vector<int>& matchsticks)
    {
        int n = matchsticks.size();
        if (n < 4)   return false;

        int sum = 0;
        for (int x : matchsticks)  sum += x;

        if (sum % 4) return false;

        int target = sum / 4;
        vector<int>sides(4);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        return helper(0, matchsticks, sides, target);
    }

    bool helper(int i, vector<int>&matchsticks, vector<int>&sides, int &target)
    {
        if (i == matchsticks.size())
        {
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }

        for (int j = 0; j < 4; j++)
        {
            int k = j - 1;

            while (k >= 0)   if (sides[k--] == sides[j])    break;

            if (k != -1) continue;
            if (sides[j] + matchsticks[i] > target)  continue;
            sides[j] += matchsticks[i];
            if (helper(i + 1, matchsticks, sides, target)) return true;
            sides[j] -= matchsticks[i];
        }

        return false;
    }
};