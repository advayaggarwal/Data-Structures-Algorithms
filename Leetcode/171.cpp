//From right to left. O(nlogn)
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int p = 0;
        int ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            ans += pow(26, p) * (columnTitle[i] - 'A' + 1);
            p++;
        }

        return ans;
    }
};


//From left to right, O(n)
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = ans * 26 + (columnTitle[i] - 'A' + 1);
        }

        return ans;
    }
};