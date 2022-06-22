class Solution {
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int>res;
        for (int i = 1; i <= 8; i++)
        {
            int n = i;
            for (int j = i + 1; j <= 9; j++)
            {
                n = n * 10 + j;
                if (n >= low && n <= high)   res.push_back(n);
                if (n > high)    break;
            }
        }

        sort(res.begin(), res.end());
        return res;
    }
};

//BFS
class Solution {
public:
    vector<int> sequentialDigits(int low, int high)
    {
        vector<int>res;

        queue<int>q;
        for (int i = 1; i <= 8; i++) q.push(i);

        while (!q.empty())
        {
            int n = q.front();
            q.pop();

            if (n >= low && n <= high)   res.push_back(n);
            if (n > high)    break;

            int ld = n % 10;

            if (ld < 9)
            {
                int nn = n * 10 + (ld + 1);
                q.push(nn);
            }
        }

        return res;
    }
};