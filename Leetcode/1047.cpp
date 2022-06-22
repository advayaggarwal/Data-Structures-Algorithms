//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    string removeDuplicates(string s) {

        stack<char>st;
        string res;
        for (char ch : s)
        {
            if (st.empty() || st.top() != ch)
            {
                st.push(ch);
            }

            else if (!st.empty() && st.top() == ch) st.pop();
        }

        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

//Time complexity - O(n)
//Space complexity - O(1)
string removeDuplicates(string S) {
    string res = "";
    for (char& c : S)
        if (res.size() && c == res.back())
            res.pop_back();
        else
            res.push_back(c);
    return res;
}