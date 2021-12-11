//Time complexity - O(m*n)
class Solution {
public:
    string multiply(string num1, string num2)
    {
        if (num1.size() < num2.size()) swap(num1, num2); //such that num1 always greater than num2

        int n1 = num1.size(), n2 = num2.size();

        int i = n1 - 1, j = n2 - 1;
        int count = 0;
        string res;

        while (j >= 0)
        {
            int carry = 0;
            string ans;
            while (i >= 0 or carry)
            {
                int digit = carry;

                if (i >= 0 && j >= 0)    digit += (num1[i--] - '0') * (num2[j] - '0');
                ans += to_string(digit % 10);
                carry = digit / 10;
            }
            reverse(ans.begin(), ans.end());
            for (int k = 0; k < count; k++)   ans += '0';
            count++;

            add(res, ans);
            i = n1 - 1;
            j--;
        }

        if (allZero(res)) return "0";

        return res;
    }

    void add(string &res, string ans)
    {
        int m = res.size(), n = ans.size();
        string result;

        int i = m - 1, j = n - 1, carry = 0;


        while (i >= 0 or j >= 0 or carry)
        {
            int digit = carry;

            if (i >= 0)    digit += res[i--] - '0';
            if (j >= 0)    digit += ans[j--] - '0';

            result += to_string(digit % 10);
            carry = digit / 10;
        }

        reverse(result.begin(), result.end());
        res = result;
    }

    bool allZero(string &res)
    {
        int n = res.size();
        for (int i = 0; i < n; i++)
        {
            if (res[i] != '0')   return false;
        }

        return true;
    }
};

//Time complexity - O(m*n)
class Solution {
public:
    string multiply(string num1, string num2) {
        // handle edge-case where the product is 0
        if (num1 == "0" || num2 == "0") return "0";

        // num1.size() + num2.size() == max no. of digits
        vector<int> num(num1.size() + num2.size(), 0);

        // build the number by multiplying one digit at the time
        for (int i = num1.size() - 1; i >= 0; --i) {
            for (int j = num2.size() - 1; j >= 0; --j) {
                num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                num[i + j] += num[i + j + 1] / 10;
                num[i + j + 1] %= 10;
            }
        }

        // skip leading 0's
        int i = 0;
        while (i < num.size() && num[i] == 0) ++i;

        // transofrm the vector to a string
        string res = "";
        while (i < num.size()) res.push_back(num[i++] + '0');

        return res;
    }
};