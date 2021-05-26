//Time complexity - O(n)
//Space complexity - O(n)
//Using Stack - NGR(Nearest greater to right)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        //have to find nearest greater to right indices
        vector<int>res = ngr(temperatures);
        int n = temperatures.size();
        for (int i = 0; i < n; i++)  res[i] -= i;

        return res;
    }


    vector<int> ngr(vector<int>& temperatures)
    {
        stack<int>s;
        int n = temperatures.size();

        vector<int>v;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s.empty())   v.push_back(i);

            else if (temperatures[s.top()] > temperatures[i])  v.push_back(s.top());

            else
            {
                while (!s.empty() && temperatures[s.top()] <= temperatures[i])   s.pop();

                if (s.empty())   v.push_back(i);
                else v.push_back(s.top());
            }

            s.push(i);
        }


        reverse(v.begin(), v.end());
        //for(auto ele:v) cout<<ele<<" ";
        return v;
    }
};




//Time complexity - O(n)
//Space complexity - O(1)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int>res(n);

        res[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n;)
            {
                if (temperatures[j] > temperatures[i])
                {
                    res[i] = j - i;
                    break;
                }

                else
                {
                    if (res[j] == 0)
                    {
                        res[i] = 0;
                        break;
                    }
                    j += res[j];
                }
            }
        }

        return res;

    }
};