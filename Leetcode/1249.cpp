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

//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    string minRemoveToMakeValid(string s)
    {
        int n = s.size();

        stack<int>stk;

        for (int i = 0; i < n; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')  continue;
            else if (s[i] == '(') stk.push(i);
            else // ')'
            {
                if (stk.empty()) s[i] = '*';
                else stk.pop();
            }
        }

        while (!stk.empty())
        {
            s[stk.top()] = '*';
            stk.pop();
        }

        string res;

        for (int i = 0; i < n; i++)
        {
            if (s[i] != '*') res += s[i];
        }

        return res;
    }
};

//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    string minRemoveToMakeValid(string s)
    {
        int n = s.size();

        int count = 0; //opening-closing count && closing-opening count

        //from left to right
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')    count++;
            if (s[i] == ')')
            {
                if (count == 0)  s[i] = '*';
                else count--;
            }
        }

        count = 0;
        //from right to left
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == ')')    count++;
            if (s[i] == '(')
            {
                if (count == 0)  s[i] = '*';
                else count--;
            }
        }

        string res;
        for (char &ch : s)
        {
            if (ch != '*')   res += ch;
        }

        return res;
    }
};