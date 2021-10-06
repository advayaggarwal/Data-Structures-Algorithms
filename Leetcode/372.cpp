class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int etf_M = (1337 * (7 - 1) * (191 - 1)) / (7 * 191); //euler totient function = 1140

        int bmod = 0;
        for (int val : b)
        {
            bmod = (bmod * 10 + val) % 1140;

        }
        return binary_exp(a, bmod, 1337);
    }

    int binary_exp(int a, int b, int m)
    {
        int res = 1;
        a %= m;

        while (b)
        {
            if (b & 1) res = (res * 1LL * a) % m;

            a = (a * 1LL * a) % m;
            b >>= 1;
        }

        return res;
    }
};