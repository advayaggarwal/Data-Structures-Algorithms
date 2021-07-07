//Idea behind recursion -  We will build the string of length l and use it to build the string of length l+1
// And we generated all the possible strings of length n and returned the kth string
//This will automatically be sorted as we are first inserting a then b and then c
class Solution {
public:

    void helper(char last_char, int i, int n, string temp, vector<string>&ans)
    {
        if (i == n)
        {
            ans.push_back(temp);
            return ;
        }

        if (last_char != 'a')
        {
            helper('a', i + 1, n, temp + 'a', ans);
        }

        if (last_char != 'b')
        {
            helper('b', i + 1, n, temp + 'b', ans);
        }

        if (last_char != 'c')
        {
            helper('c', i + 1, n, temp + 'c', ans);
        }
    }

    string getHappyString(int n, int k) {

        vector<string>ans;
        char ch;
        helper(ch, 0, n, "", ans);

        return k > ans.size() ? "" : ans[k - 1];
    }
};


//We can optimise the above solution by not generating all the possible strings of length n, and only generating the
// strings till k

class Solution {
public:

    void helper(char last_char, int i, int n, string temp, vector<string>&ans, int k)
    {

        if (ans.size() == k) return;

        if (i == n)
        {
            ans.push_back(temp);
            return ;
        }

        if (last_char != 'a')
        {
            helper('a', i + 1, n, temp + 'a', ans, k);
        }

        if (last_char != 'b')
        {
            helper('b', i + 1, n, temp + 'b', ans, k);
        }

        if (last_char != 'c')
        {
            helper('c', i + 1, n, temp + 'c', ans, k);
        }
    }

    string getHappyString(int n, int k) {

        vector<string>ans;
        char ch;
        helper(ch, 0, n, "", ans, k);

        return k > ans.size() ? "" : ans[k - 1];
    }
};