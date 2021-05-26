//Time complexity - O(n)
//Space complexity - O(n), considering recursive stack

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decodeString(s, i);
    }

    string decodeString(string &s, int &i)
    {
        string res;

        while (i < s.length() && s[i] != ']')
        {
            if (isdigit(s[i]))
            {
                int k = 0;
                while (i < s.length() && isdigit(s[i]))
                {
                    k = k * 10 + s[i++] - '0'; //for calculating the number if it consists of more than 1 digit
                }
                i++; //opening bracket

                string r = decodeString(s, i);
                while (k--)  res += r;
                i++; //closing bracket
            }
            else
            {
                res += s[i++];
            }
        }


        return res;
    }
};


//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    string decodeString(string s) {
        stack<string>st;
        stack<int>count;

        string res;
        int i = 0;

        while (i < s.size())
        {
            if (isdigit(s[i]))
            {
                int num = 0;
                while (isdigit(s[i]))
                {
                    num = num * 10 + s[i] - '0';
                    i++;
                }

                count.push(num);
            }
            else if (s[i] == '[')
            {
                st.push(res);
                res = "";

                i++;
            }
            else if (s[i] == ']')
            {
                string temp = st.top();
                st.pop();
                int times = count.top();
                count.pop();

                while (times--)  temp += res;

                res = temp;
                i++;
            }

            else
            {
                res += s[i];
                i++;
            }
        }

        return res;
    }
};