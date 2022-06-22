//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    bool digitCount(string num)
    {
        int n = num.size();
        vector<int>count(10);
        for (int i = 0; i < n; i++)  count[num[i] - '0']++;

        for (int i = 0; i < n; i++)
        {
            if (count[i] != num[i] - '0') return false;
        }

        return true;
    }
};