//Time complexity - O(k^n)
//Space complexity - O(n)
class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k)
    {
        int n = cookies.size();
        if (n == k) //if number of students is equal to number of bags, then maximum cookie will be the ans
        {
            int ans = 0;
            for (int i = 0; i < n; i++)  ans = max(ans, cookies[i]);
            return ans;
        }
        vector<int>s(k); //storing cookies each student gets
        return recur(cookies, n, 0, s, k);
    }

    int recur(vector<int>& cookies, int n, int i, vector<int>&s, int k)
    {
        if (i == n)
        {
            int ans = 0;
            for (int i = 0; i < k; i++)  ans = max(ans, s[i]);
            return ans;
        }

        int res = INT_MAX;

        for (int j = 0; j < k; j++) //giving ith cookies to jth student
        {
            s[j] += cookies[i];
            res = min(res, recur(cookies, n, i + 1, s, k));
            s[j] -= cookies[i]; //backtrack
        }

        return res;
    }
};