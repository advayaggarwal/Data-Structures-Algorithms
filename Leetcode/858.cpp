//Time complexity - O(logp)
//Space complexity - O(1)
class Solution {
public:
    int mirrorReflection(int p, int q)
    {
        // m*p = n*q
        int m = 1, n = 1;

        while (m * p != n * q)
        {
            n++;
            m = (n * q) / p;
        }

        if (n % 2 == 0)    return 2;
        else if (m % 2 == 0)   return 0;
        return 1;
    }
};