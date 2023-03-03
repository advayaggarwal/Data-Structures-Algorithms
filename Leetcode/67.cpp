//Time complexity - O(max(m, n))
//Space complexity - O(1)
class Solution {
public:
    string addBinary(string a, string b)
    {
        string ans;
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;

        while (i >= 0 or j >= 0 or carry)
        {
            int sum = 0;
            if (i >= 0)  sum += (a[i--] - '0');
            if (j >= 0)  sum += (b[j--] - '0');
            if (carry)   sum += carry;

            ans += (sum % 2 + '0');
            carry = sum / 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
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