//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    string minRemoveToMakeValid(string s)
    {
        int n = s.size();
        vector<char>character(n);
        for (int i = 0; i < n; i++)  character[i] = s[i];

        stack<int>st;

        for (int i = 0; i < n; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z') continue;

            else if (s[i] == '(')   st.push(i);

            else
            {
                if (st.empty())  character[i] = '*'; //Should not be included, this '(' has no opening pair, therfore invalid
                else st.pop();
            }
        }

        while (!st.empty()) //Remaining '(' are also invalid
        {
            character[st.top()] = '*';
            st.pop();
        }

        string res;
        for (int i = 0; i < n; i++)
        {
            if (character[i] != '*')   res += character[i];
        }

        return res;
    }
};