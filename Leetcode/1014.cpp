//Brute Force
//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values)
    {
        int ans = INT_MIN;
        int n = values.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                ans = max(ans, values[i] + values[j] + i - j);
            }
        }

        return ans;
    }
};

//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values)
    {
        //Maximise -> values[i]+values[j]+i-j = (values[i]+i) + (values[j]-j);
        int ans = INT_MIN;
        int n = values.size();
        int maxi = values[0] + 0; //maximum (values[i]+i) value so far

        for (int i = 1; i < n; i++)
        {
            ans = max(ans, maxi + values[i] - i);
            maxi = max(maxi, values[i] + i);
        }

        return ans;
    }
};