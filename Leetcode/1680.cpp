//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    int concatenatedBinary(int n)
    {
        string res;
        for (int i = 1; i <= n; i++)
        {
            string temp;
            int no = i;
            while (no)
            {
                if (no & 1)  temp += '1';
                else temp += '0';
                no >>= 1;
            }
            reverse(temp.begin(), temp.end());
            res += temp;
        }

        int mod = 1e9 + 7;
        long long ans = 0;
        for (int i = 0; i < res.size(); i++)
        {
            ans <<= 1;
            ans += (res[i] == '1' ? 1 : 0);
            ans %= mod;
        }

        return ans;
    }
};

//Time complexity - O(nlogn)
//Space complexity - O(1)
class Solution {
public:
    int numberOfBits(int n)
    {
        return log2(n) + 1;
    }

    int concatenatedBinary(int n)
    {
        long ans = 0, MOD = 1e9 + 7;

        for (int i = 1; i <= n; ++i)
        {
            int len = numberOfBits(i);
            ans = ((ans << len) % MOD + i) % MOD;
        }

        return ans;
    }
};

/*

With the observation that the len only increment when the i is a power of 2,
we can increment len only when i has a single bit 1. We can check this via (i & (i - 1)) == 0

Time complexity - O(n)
Space complexity - O(1)

*/
class Solution {
public:
    int concatenatedBinary(int n)
    {
        long ans = 0, mod = 1e9 + 7, len = 0;
        for (int i = 1; i <= n; ++i)
        {
            if ((i & (i - 1)) == 0) ++len;
            ans = ((ans << len) % mod + i) % mod;
        }

        return ans;
    }
};