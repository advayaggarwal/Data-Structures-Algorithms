//Brute Force
//Time complexity - O(n^3)
//Space complexity - O(1)
class Solution {
public:
    int longestValidParentheses(string s)
    {
        int n = s.size(), ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                string temp = s.substr(i, j - i + 1);
                if (isValid(temp))   ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }

    bool isValid(string &s)
    {
        int n = s.size(), open = 0, close = 0;
        for (int i = 0; i < n; i++)
        {
            if (close > open)   return false;

            if (s[i] == '(') open++;
            else close++;
        }

        return open == close;
    }
};

//Optimisation to Brute force, calculating on the go
//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    int longestValidParentheses(string s)
    {
        int n = s.size(), ans = 0;

        for (int i = 0; i < n; i++)
        {
            int open = 0, close = 0;
            for (int j = i; j < n; j++)
            {
                if (s[j] == '(') open++;
                else close++;

                if (close > open)    break;
                else if (close == open)  ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};

//Using 2 Stacks
//Time complexity - O(n)
//Space complexity - O(2*n)
class Solution {
public:
    int longestValidParentheses(string s)
    {
        stack<char>ch;
        stack<int>index; //indices in string s which can cause a problem in forming a valid parentheses
        index.push(-1);
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                ch.push(s[i]);
                index.push(i); //can cause a problem, if corresponding closing parentheses found, then pop it
            }

            else
            {
                if (!ch.empty() && ch.top() == '(')
                {
                    ch.pop();
                    index.pop();
                    ans = max(ans, i - index.top());
                }

                else index.push(i); //definitely a problem
            }
        }

        return ans;
    }
};

//Using DP
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int longestValidParentheses(string s)
    {
        int ans = 0;
        int n = s.size();
        vector<int>dp(n + 1); //dp[i] denotes length of longest valid parentheses ending at i

        for (int i = 1; i < n; i++)
        {
            int j = i - dp[i] - 1;

            if (s[i] == ')' && j >= 0 && s[j] == '(')  dp[i + 1] = dp[i] + dp[j] + 2;

            ans = max(ans, dp[i + 1]);
        }

        return ans;
    }
};

//Using 1 Stack
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int longestValidParentheses(string s)
    {
        int ans = 0;
        int n = s.size();
        stack<int>st;
        st.push(-1);

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(') st.push(i);
            else
            {
                st.pop();
                if (st.empty())  st.push(i);
                else ans = max(ans, i - st.top());
            }
        }

        return ans;
    }
};

//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int longestValidParentheses(string s)
    {
        int ans = 0;
        int n = s.size();
        int open = 0, close = 0;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(') open++;
            else close++;

            if (open == close)   ans = max(ans, 2 * open);
            else if (close > open)   open = close = 0;
        }

        open = 0, close = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '(') open++;
            else close++;

            if (open == close)   ans = max(ans, 2 * open);
            else if (open > close)   open = close = 0;
        }

        return ans;
    }
};