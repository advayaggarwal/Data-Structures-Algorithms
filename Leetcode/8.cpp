//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int myAtoi(string s)
    {
        long long int ans = 0;
        int sign = 1;
        int index = 0;
        int n = s.size();

        while (index < n && s[index] == ' ') index++;

        if (index < n && s[index] == '+')
        {
            sign = 1;
            index++;
        }

        else if (index < n && s[index] == '-')
        {
            sign = -1;
            index++;
        }

        while (index < n && isdigit(s[index]))
        {
            int digit = s[index] - '0';

            if (ans > INT_MAX)   return sign == 1 ? INT_MAX : INT_MIN;

            ans = ans * 10 + digit;
            index++;
        }

        if (ans > INT_MAX)  return sign == 1 ? INT_MAX : INT_MIN;
        return  ans *= sign;;
    }
};