//Time complexity - O(nlogn)
//Space complexity - O(n)
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime)
    {
        int n = neededTime.size(), ans = 0;
        for (int i = 0; i < n;)
        {
            multiset<int>s;
            s.insert(neededTime[i]);
            int j = i + 1;
            while (j < n && colors[j] == colors[i])
            {
                s.insert(neededTime[j]);
                j++;
            }

            while (s.size() > 1)
            {
                auto it = s.begin();
                ans += *it;
                s.erase(it);
            }
            i = j;
        }

        return ans;
    }
};

//Double Pass solution
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime)
    {
        int n = neededTime.size(), ans = 0;
        for (int i = 0, j = i; i < n;)
        {
            int sum = 0, maxi = 0;
            while (j < n && colors[j] == colors[i])
            {
                sum += neededTime[j];
                maxi = max(maxi, neededTime[j]);
                j++;
            }

            ans += (sum - maxi);
            i = j;
        }

        return ans;
    }
};

//Single Pass Solution
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int minCost(string colors, vector<int>& neededTime)
    {
        int n = neededTime.size(), ans = 0, currMaxTime = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && colors[i] != colors[i - 1])   currMaxTime = 0;

            ans += min(neededTime[i], currMaxTime);
            currMaxTime = max(currMaxTime, neededTime[i]);
        }

        return ans;
    }
};