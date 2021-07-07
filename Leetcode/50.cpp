//Time complexity - O(logn)
//Space complexity - O(1)

class Solution {
public:
    double myPow(double x, int n) {

        double res = 1.0;

        long long int nn = n; //long long as range of -ve numbers is greater than +ve numbers
        //so if n = -2147483648, nn should be 2147483648, and we can't store this number in int(-2147483648 to 2147483647)
        if (nn < 0) nn = -nn;

        while (nn)
        {
            if (nn % 2)    res = res * x;

            x *= x;
            nn /= 2;
        }

        if (n < 0)   res = 1 / res;

        return res;

    }
};