//Time complexity - O(n)
//Space complexity - O(2*n)
class Solution {
public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.size(), nearestLeftIndex = -1, nearestRightIndex = -1;
        vector<int>lforce(n, -1), rforce(n, -1);

        for (int i = n - 1; i >= 0; i--)
        {
            if (dominoes[i] == 'L') nearestLeftIndex = i;
            else if (dominoes[i] == 'R')   nearestLeftIndex = -1;
            lforce[i] = nearestLeftIndex;
        }

        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] == 'L') nearestRightIndex = -1;
            else if (dominoes[i] == 'R')   nearestRightIndex = i;
            rforce[i] = nearestRightIndex;
        }

        string res;
        for (int i = 0; i < n; i++)
        {
            int leftDiff = lforce[i] == -1 ? INT_MAX : (lforce[i] - i);
            int rightDiff = rforce[i] == -1 ? INT_MAX : (i - rforce[i]);

            if (leftDiff < rightDiff)   res += 'L';
            else if (leftDiff > rightDiff) res += 'R';
            else res += '.';
        }

        return res;
    }
};

//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    string pushDominoes(string dominoes)
    {
        int n = dominoes.size(), nearestLeftIndex = -1, nearestRightIndex = -1;
        vector<int>lforce(n, -1), rforce(n, -1);

        for (int i = n - 1; i >= 0; i--)
        {
            if (dominoes[i] == 'L') nearestLeftIndex = i;
            else if (dominoes[i] == 'R')   nearestLeftIndex = -1;
            lforce[i] = nearestLeftIndex;
        }

        string res;
        for (int i = 0; i < n; i++)
        {
            if (dominoes[i] == 'L') nearestRightIndex = -1;
            else if (dominoes[i] == 'R')   nearestRightIndex = i;

            int rforce = nearestRightIndex;

            int leftDiff = lforce[i] == -1 ? INT_MAX : (lforce[i] - i);
            int rightDiff = rforce == -1 ? INT_MAX : (i - rforce);

            if (leftDiff < rightDiff)   res += 'L';
            else if (leftDiff > rightDiff) res += 'R';
            else res += '.';
        }

        return res;
    }
};

class Solution {
public:
    string pushDominoes(string d)
    {
        d = 'L' + d + 'R';
        string res = "";
        for (int i = 0, j = 1; j < d.length(); ++j)
        {
            if (d[j] == '.') continue;
            int middle = j - i - 1;
            if (i > 0)
                res += d[i];
            if (d[i] == d[j])
                res += string(middle, d[i]);
            else if (d[i] == 'L' && d[j] == 'R')
                res += string(middle, '.');
            else
                res += string(middle / 2, 'R') + string(middle % 2, '.') + string(middle / 2, 'L');
            i = j;
        }

        return res;
    }
};