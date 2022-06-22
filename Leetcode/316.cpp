//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    string removeDuplicateLetters(string s)
    {
        stack<char>st;
        vector<int>freq(26);
        vector<bool>exists(26);

        for (char &ch : s)   freq[ch - 'a']++;

        for (char &ch : s)
        {
            freq[ch - 'a']--;
            if (!exists[ch - 'a'])
            {
                while (!st.empty() && st.top() > ch && freq[st.top() - 'a'] > 0)
                {
                    exists[st.top() - 'a'] = false;
                    st.pop();
                }

                st.push(ch);
                exists[ch - 'a'] = true;
            }
        }

        string res;
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());

        return res;
    }
};