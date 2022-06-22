class Solution {
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (!numerator)  return "0";
        string ans;

        if ((numerator > 0) ^ (denominator > 0)) ans += '-';

        long n = labs(numerator), d = labs(denominator), r = n % d;
        ans += to_string(n / d);
        if (!r)  return ans;
        ans += '.';

        unordered_map<long, int>m;
        while (r)
        {
            if (m.count(r)) //remainder is repeating
            {
                ans.insert(m[r], "("); //insert "(" before r occured
                ans += ')';
                break;
            }

            m[r] = ans.size(); //placing the starting index as the value of r in the map
            r *= 10;
            ans += to_string(r / d);
            r %= d;
        }

        return ans;
    }
};