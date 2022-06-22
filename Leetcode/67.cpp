//Time complexity - O(max(m, n))
//Space complexity - O(1)
class Solution {
public:
    string addBinary(string a, string b)
    {
        int carry = 0;
        int m = a.size() - 1, n = b.size() - 1;
        string res;

        while (m >= 0 or n >= 0)
        {
            int d1 = m >= 0 ? a[m--] - '0' : 0;
            int d2 = n >= 0 ? b[n--] - '0' : 0;
            int sum = d1 + d2 + carry;
            if (sum == 0)
            {
                res += '0';
                carry = 0;
            }

            else if (sum == 1)
            {
                res += '1';
                carry = 0;
            }

            else if (sum == 2)
            {
                res += '0';
                carry = 1;
            }

            else
            {
                res += '1';
                carry = 1;
            }
        }

        if (carry) res += '1';

        reverse(res.begin(), res.end());
        return res;
    }
};

//Time complexity - O(max(m, n))
//Space complexity - O(1)
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string s = "";

        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }

        return s;
    }
};