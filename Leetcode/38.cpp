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