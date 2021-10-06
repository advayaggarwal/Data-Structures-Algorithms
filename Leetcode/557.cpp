class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;
        string res;

        while (i < n)
        {
            string temp;
            while (s[i] != ' ' and i < n)
            {
                temp += s[i++];
            }
            i++;
            reverse(temp.begin(), temp.end());

            res += temp + " ";
        }
        res.pop_back();
        return res;
    }
};