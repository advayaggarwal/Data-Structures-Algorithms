class Solution {
public:
    int reverse(int x) {

        string s = to_string(x);

        int n = s.size();
        bool isNegative = false;

        long long int ans = 0, base = 1;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '-')
            {
                isNegative = true;
                continue;
            }

            ans += ((s[i] - '0') * 1LL * base);
            if (ans > INT_MAX)   return 0;

            base *= 10;
        }

        return isNegative ? -ans : ans;
    }
};


class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            //We can avoid these comparisons by using long long, but in ques it is specified not to use long long
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};