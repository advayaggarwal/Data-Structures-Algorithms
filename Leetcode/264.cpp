//Brute Force
//Time complexity - O(i*logn), where i is very large as compared to n, 1407th ugly number is 536870912
class Solution {
public:
    int nthUglyNumber(int n)
    {
        vector<int>ugly;
        ugly.push_back(1);

        for (int i = 2; ugly.size() < n; i++)
        {
            if (isUgly(i))   ugly.push_back(i);
        }

        return ugly[n - 1];
    }

    bool isUgly(int n) //O(logn)
    {
        while (n % 2 == 0)   n /= 2;
        while (n % 3 == 0)   n /= 3;
        while (n % 5 == 0)   n /= 5;

        return n == 1;
    }
};

//BFS
//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    int nthUglyNumber(int n)
    {
        set<long long int>possibleNums;
        vector<long long int>ugly;
        possibleNums.insert(1);

        while (ugly.size() < n)
        {
            auto it = possibleNums.begin();
            long long int no = *it;
            ugly.push_back(no);
            possibleNums.erase(it);

            possibleNums.insert(2 * no);
            possibleNums.insert(3 * no);
            possibleNums.insert(5 * no);
        }

        return ugly[n - 1];
    }
};

//DP
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int nthUglyNumber(int n)
    {
        int t2 = 0, t3 = 0, t5 = 0;

        vector<int>dp(n);
        dp[0] = 1;

        for (int i = 1; i < n; i++)
        {
            dp[i] = min(dp[t2] * 2, min(dp[t3] * 3, dp[t5] * 5));
            if (dp[i] == dp[t2] * 2)   t2++;
            if (dp[i] == dp[t3] * 3)   t3++;
            if (dp[i] == dp[t5] * 5)   t5++;
        }

        return dp[n - 1];
    }
};