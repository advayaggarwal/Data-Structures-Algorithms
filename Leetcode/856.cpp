//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int scoreOfParentheses(string s)
    {
        stack<int>st;
        for (char &c : s)
        {
            if (c == '(')    st.push(-1);

            else
            {
                int val = 0;
                while (st.top() != -1)
                {
                    val += st.top();
                    st.pop();
                }
                st.pop();
                if (val != 0)    st.push(2 * val);
                else st.push(1);
            }
        }

        int ans = 0;
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int scoreOfParentheses(string s)
    {
        int ans = 0, depth = 0, n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(') depth++;
            else
            {
                depth--;
                if (s[i - 1] == '(')   ans += 1 << depth;
            }
        }

        return ans;
    }
};