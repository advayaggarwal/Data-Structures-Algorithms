//Time complexity - O(n^2)
//Space complexity - O(n)
class Solution {
public:
    vector<int> movesToStamp(string stamp, string target)
    {
        int n = target.size();
        string targetStr = string(n, '*');

        vector<int>res;
        while (target != targetStr)
        {
            int stampIndex = fetchStampIndex(target, stamp);
            if (stampIndex < 0)  return {};
            else    update(target, stampIndex, stamp);
            res.push_back(stampIndex);
        }

        reverse(res.begin(), res.end());
        return res;
    }

    int fetchStampIndex(string &target, string &stamp)
    {
        for (int i = 0; i <= target.size() - stamp.size(); i++)
        {
            int j = 0, s = i;
            bool nonStarChar = false;
            while (j < stamp.size() && s < target.size() && (target[s] == '*' or target[s] == stamp[j]))
            {
                if (target[s] != '*')    nonStarChar = true;
                s++;
                j++;
            }

            if (j == stamp.size() && nonStarChar)   return i;
        }

        return -1;
    }

    void update(string &target, int i, string &stamp)
    {
        for (int j = 0; j < stamp.size(); j++)   target[i + j] = '*';
    }
};