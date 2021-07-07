//Time complexity - O(n)
//Space complexity - O(n)

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        if (n == 0)    return 0;
        stack<int>st;
        int currentNumber = 0;
        char operation = '+'; //so that 1st digit get pushed into the stack
        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
            {
                currentNumber = (currentNumber * 10) + (s[i] - '0');
            }

            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1) //i==n-1, so that we perform the last operation
            {
                if (operation == '+')
                {
                    st.push(currentNumber);
                }
                else if (operation == '-')
                {
                    st.push(-currentNumber);
                }
                else if (operation == '*')
                {
                    int op = st.top();
                    st.pop();
                    st.push(op * currentNumber);
                }
                else if (operation == '/')
                {
                    int op = st.top();
                    st.pop();
                    st.push(op / currentNumber);
                }
                operation = s[i];
                currentNumber = 0;
            }
        }

        int res = 0;
        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }
        return res;
    }
};


//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        if (n == 0)    return 0;
        int currentNumber = 0, lastNumber = 0;
        int res = 0;
        char operation = '+'; //so that 1st digit get added into the result
        for (int i = 0; i < n; i++)
        {
            if (isdigit(s[i]))
            {
                currentNumber = (currentNumber * 10) + (s[i] - '0');
            }

            if (!isdigit(s[i]) && s[i] != ' ' || i == n - 1)//i==n-1, so that we perform the last operation
            {
                if (operation == '+')
                {
                    res += lastNumber;
                    lastNumber = currentNumber;
                }
                else if (operation == '-')
                {
                    res += lastNumber;
                    lastNumber = -currentNumber;
                }
                else if (operation == '*')
                {
                    lastNumber *= currentNumber;
                }
                else if (operation == '/')
                {
                    lastNumber /= currentNumber;
                }
                operation = s[i];
                currentNumber = 0;
            }
        }

        res += lastNumber;
        return res;
    }
};