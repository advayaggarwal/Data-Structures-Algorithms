//Time complexity - O(n), n is the size of sentence
//Space complexity - O(n)
class Solution {
public:
    string discountPrices(string sentence, int discount)
    {
        stringstream ss(sentence);
        string s;
        vector<string>v;
        while (ss >> s)  v.push_back(s);
        string res;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i][0] == '$')
            {
                if (isDigit(v[i], 1))
                {
                    string d = v[i].substr(1);
                    long double p = stold(d);
                    long double price = (p * 1.0) - (p * discount) / (100 * 1.0);
                    d = to_string(price);
                    string temp;
                    for (int j = 0; j < d.size(); j++)
                    {
                        if (d[j] == '.')
                        {
                            temp += d[j];
                            if (j + 1 < d.size()) temp += d[j + 1];
                            if (j + 2 < d.size())  temp += d[j + 2];
                            break;
                        }

                        else temp += d[j];
                    }
                    temp = '$' + temp;
                    res += temp + " ";
                }

                else res += v[i] + " ";
            }

            else res += v[i] + " ";
        }
        res.pop_back();
        return res;
    }

    bool isDigit(string s, int i)
    {
        if (i >= s.size())   return false;
        for (int j = i; j < s.size(); j++)
        {
            if (s[j] < '0' or s[j] > '9')    return false;
        }

        return true;
    }
};