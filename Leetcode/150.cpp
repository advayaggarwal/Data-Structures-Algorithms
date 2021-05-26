class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int>s;

        int n = tokens.size();
        for (int i = 0; i < n; i++)
        {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")    s.push(stoi(tokens[i]));

            else
            {
                int op2 = s.top();
                s.pop();
                int op1 = s.top();
                s.pop();

                if (tokens[i] == "+")
                {
                    int res = (op1 + op2);
                    s.push(res);
                }
                else if (tokens[i] == "-")
                {
                    int res = (op1 - op2);
                    s.push(res);
                }
                else if (tokens[i] == "*")
                {
                    int res = (op1 * op2);
                    s.push(res);
                }
                else
                {
                    int res = (op1 / op2);
                    s.push(res);
                }
            }
        }

        return s.top();

    }
};