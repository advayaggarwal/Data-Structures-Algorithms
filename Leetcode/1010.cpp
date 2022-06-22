//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time)
    {
        int n = time.size(), count = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if ((time[i] + time[j]) % 60 == 0)   count++;
            }
        }

        return count;
    }
};

//Using map
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time)
    {
        int n = time.size(), count = 0;
        vector<int>m(60);
        for (int i = 0; i < n; i++)
        {
            int temp = time[i] % 60 == 0 ? 0 : 60 - (time[i] % 60);
            count += m[temp];
            m[time[i] % 60]++;
        }

        return count;
    }
};