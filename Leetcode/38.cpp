//Recursive
class Solution {
public:
    string countAndSay(int n)
    {
        if (n == 1)  return "1";
        string ans = countAndSay(n - 1);
        string res;
        int count = 0;
        for (int i = 0; i < ans.size();)
        {
            count = 1;
            int j = i + 1;
            for (; j < ans.size(); j++)
            {
                if (ans[j] == ans[i])   count++;
                else break;
            }

            res += to_string(count) + ans[i];
            i = j;
        }

        return res;
    }
};

//Iterative
class Solution {
public:
    string countAndSay(int n)
    {
        string res = "1";
        while (--n)
        {
            string cur = "";
            for (int i = 0; i < res.size(); i++)
            {
                int count = 1;
                while ((i + 1 < res.size()) && (res[i] == res[i + 1]))
                {
                    count++;
                    i++;
                }
                cur += to_string(count) + res[i];
            }
            res = cur;
        }
        return res;
    }
};