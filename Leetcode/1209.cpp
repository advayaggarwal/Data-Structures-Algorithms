//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>>st;

        for (char &ch : s)
        {
            if (st.empty() or st.top().first != ch)
            {
                st.push({ch, 1});
            }

            else if (ch == st.top().first && st.top().second < k - 1)
            {
                st.push({ch, st.top().second + 1});
            }

            else if (st.top().second == k - 1)
            {
                int count = k - 1;
                while (!st.empty() && count--)
                {
                    st.pop();
                }
            }
        }

        string res;
        while (!st.empty())
        {
            res += st.top().first;
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    string removeDuplicates(string s, int k)
    {
        stack<pair<char, int>>st;
        st.push({'#', 0});

        for (char &ch : s)
        {
            if (st.top().first != ch)
            {
                st.push({ch, 1});
            }

            else if (++st.top().second == k)
            {
                st.pop();
            }
        }

        string res;
        while (!st.empty())
        {
            res += string(st.top().second, st.top().first);
            st.pop();
        }

        reverse(res.begin(), res.end());

        return res;
    }
};

//Can use vector as stack
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    string removeDuplicates(string s, int k)
    {
        vector<pair<char, int>>st = {{'#', 0}};

        for (char &ch : s)
        {
            if (st.back().first != ch)
            {
                st.push_back({ch, 1});
            }

            else if (++st.back().second == k)
            {
                st.pop_back();
            }
        }

        string res;
        for (auto &p : st)
        {
            res.append(p.second, p.first);
        }

        return res;
    }
};