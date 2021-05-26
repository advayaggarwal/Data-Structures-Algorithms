class Solution {
public:
    vector<string> generateParenthesis(int n) {

        vector<string>res;
        string op = "";
        helper(op, n, n, res);

        return res;

    }


    void helper(string &op, int opening, int closing, vector<string>&res)
    {

        if (opening == 0 && closing == 0)
        {
            res.push_back(op);
            return;
        }

        if (opening > 0)
        {
            op.push_back('(');
            helper(op, opening - 1, closing, res);
            op.pop_back();
        }

        if (closing > 0 && opening < closing)
        {
            op.push_back(')');
            helper(op, opening, closing - 1, res);
            op.pop_back();
        }

    }
};