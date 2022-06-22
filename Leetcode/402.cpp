//Recursion
//Time complexity - O(2^n)
//Space complexity - O(n)
class Solution {
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        string res, ans;
        helper(0, n, num, n - k, ans, res);

        if (res == "") return "0";
        int i = 0;

        while (i < res.size())
        {
            if (res[i] == '0')   i++;
            else break;
        }
        if (i == res.size()) return "0";
        return res.substr(i);
    }

    void helper(int i, int n, string &num, int k, string &ans, string &res)
    {
        if (i >= n)
        {
            if (k == 0)
            {
                int resInt = INT_MAX;
                if (res != "")   resInt = stoi(res);
                int ansInt = INT_MAX;
                if (ans != "")   ansInt = stoi(ans);
                if (ansInt < resInt)   res = ans;
            }
            return;
        }


        helper(i + 1, n, num, k, ans, res);
        ans += num[i];
        helper(i + 1, n, num, k - 1, ans, res);
        ans.pop_back();
    }
};

//DP
//Time complexity - O(n*k)
//Space complexity - O(n*k)
class Solution {
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        unordered_map<string, string>m;
        string res = helper(0, n, num, n - k, m);

        if (res == "") return "0";
        int i = 0;

        while (i < res.size())
        {
            if (res[i] == '0')   i++;
            else break;
        }
        if (i == res.size()) return "0";
        return res.substr(i);
    }

    string helper(int i, int n, string &num, int k, unordered_map<string, string>&m)
    {
        if (k == 0)  return "";
        if (i >= n)
        {
            if (k > 0)   return "#";
        }

        string key = to_string(i) + "#" + to_string(k);

        if (m.count(key))   return m[key];

        string op1 = helper(i + 1, n, num, k, m);
        string op2 = helper(i + 1, n, num, k - 1, m);

        int take = INT_MAX;
        int notTake = INT_MAX;
        if (op1 != "#" && op1 != "") notTake = stoi(op1);

        if (op2 != "#")
        {
            op2 = num[i] + op2;
            take = stoi(op2);
        }

        if (notTake <= take) return m[key] = op1;
        return m[key] = op2;
    }
};

//Greedy using stack
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        if (k == n)  return "0";

        stack<int>s;
        s.push(num[0] - '0');
        for (int i = 1; i < n; i++)
        {
            int no = (num[i] - '0');
            while (!s.empty() && (s.top() > no) && k)
            {
                s.pop();
                k--;
            }
            s.push(no);
        }

        string res;
        while (!s.empty() && k--)    s.pop(); //numbers are in increasing order
        while (!s.empty())
        {
            res += (s.top() + '0');
            s.pop();
        }

        reverse(res.begin(), res.end());

        int i = 0;
        while (i < res.size())
        {
            if (res[i] == '0')   i++;
            else break;
        }
        if (i == res.size())  return "0";
        return res.substr(i);
    }
};

//Greedy without stack
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    string removeKdigits(string num, int k)
    {
        int n = num.size();
        int digits = n - k;
        if (n <= k)  return "0";

        int top = -1;
        for (int i = 0; i < n; i++)
        {
            while (top >= 0 && (num[top] > num[i]) && k > 0)
            {
                top--;
                k--;
            }

            top++;
            num[top] = num[i];
        }

        int start = 0;
        while (start <= top && num[start] == '0')    start++;

        string res;
        for (int i = start; i < digits; i++)    res = res + num[i];

        if (res == "") return "0";
        return res;
    }
};