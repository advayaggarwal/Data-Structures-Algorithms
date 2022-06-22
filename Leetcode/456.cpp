//Brute Force
//Time complexity - O(n^3)
//Space complexity - O(1)
class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (nums[i] < nums[k] && nums[k] < nums[j])  return true;
                }
            }
        }

        return false;
    }
};

//Better Force
//Time complexity - O(n^2)
//Space complexity - O(1)
/*
The answer lies in the fact that once the first two numbers nums[i] and nums[j] are fixed, we are up to find the
third number nums[k] which will be within the range (nums[i], nums[j])(the two boundaries are exclusive).
Intuitively the larger the range is, the more likely there will be a number "falling into" it.
Therefore we need to choose index i which will maximize the range (nums[i], nums[j]).
Since the upper bound nums[j] is fixed, this is equivalent to minimizing the lower bound nums[i].
Thus it is clear i should be the index of the minimum element of the subarray nums[0, j) (left inclusive, right exclusive).
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        int n = nums.size();
        int mini = INT_MAX;
        for (int j = 0; j < n; j++)
        {
            mini = min(mini, nums[j]);
            if (mini == nums[j]) continue;

            for (int k = j + 1; k < n; k++)
            {
                if (mini < nums[k] && nums[k] < nums[j])  return true;
            }
        }

        return false;
    }
};

//Using Prefix array and Stack
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>prefixMin(n); //for i
        prefixMin[0] = nums[0];

        for (int i = 1; i < n; i++)  prefixMin[i] = min(prefixMin[i - 1], nums[i]);

        stack<int>st; //for k

        for (int j = n - 1; j >= 0; j--)
        {
            while (!st.empty() && st.top() <= prefixMin[j]) st.pop();
            if (!st.empty() && st.top() < nums[j])   return true;

            st.push(nums[j]);
        }

        return false;
    }
};

//Using Stack only
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    bool find132pattern(vector<int>& nums)
    {
        int n = nums.size();
        int secondMax = INT_MIN;
        stack<int>st;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] < secondMax) return true;

            while (!st.empty() && nums[i] > st.top())
            {
                secondMax = max(secondMax, st.top());
                st.pop();
            }
            //All the peaks will be added here
            st.push(nums[i]);
        }

        return false;
    }
};