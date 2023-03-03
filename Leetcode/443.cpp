//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int compress(vector<char>& chars)
    {
        int i = -1, count = 1;
        char c = chars[0];
        for (int j = 1; j < chars.size(); j++)
        {
            if (chars[j - 1] == chars[j])  count++;
            else
            {
                chars[++i] = c;
                c = chars[j];

                if (count > 1)
                {
                    string cnt = to_string(count);
                    for (char ch : cnt)
                    {
                        chars[++i] = ch;
                    }
                }

                count = 1;
            }
        }

        chars[++i] = c;

        if (count > 1)
        {
            string cnt = to_string(count);
            for (char ch : cnt)
            {
                chars[++i] = ch;
            }
        }

        return i + 1;
    }
};