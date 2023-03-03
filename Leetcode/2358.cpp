//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int maximumGroups(vector<int>& grades)
    {
        int n = grades.size();
        int ans = 1;
        while (ans * (ans + 1) / 2 <= n)   ans++;
        return ans - 1;
    }
};

//Binary Search
//Time complexity - O(logn)
//Space complexity - O(1)
class Solution {
public:
    int maximumGroups(vector<int>& grades)
    {
        int n = grades.size();
        int ans, lo = 1, hi = n;

        while (lo <= hi)
        {
            long long mid = lo + (hi - lo) / 2;

            if (mid * (mid + 1) / 2 <= n)
            {
                ans = mid;
                lo = mid + 1;
            }

            else hi = mid - 1;
        }

        return ans;
    }
};