//Brute Force
//Time complexity - O(n^2)
//Space complexity - O(1)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr)
    {
        int n = arr.size();
        int sum = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {
            int mini = INT_MAX;
            for (int j = i; j < n; j++)
            {
                mini = min(mini, arr[j]);
                sum = (sum + mini) % mod;
            }
        }

        return sum;
    }
};

//https://leetcode.com/problems/sum-of-subarray-minimums/discuss/178876/stack-solution-with-very-detailed-explanation-step-by-step/379281
/*
Using Stack
Finding the number of subarrays in which arr[i] is minimum, so it's contribution to the total sum will be -
arr[i]*number of subarrays in which arr[i] is minimum
*/
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr)
    {
        int n = arr.size(), mod = 1e9 + 7;
        stack<pair<int, int>> prev, next;

        //next smaller element to left and right
        vector<int>left(n), right(n);
        //left[i] denotes consecutive number of larger elements including arr[i] to the left
        //right[i] denotes consecutive number of larger elements including arr[i] to the right

        //filling left array
        for (int i = 0; i < n; i++)
        {
            int count = 1;
            while (!prev.empty() && prev.top().first > arr[i])
            {
                count += prev.top().second;
                prev.pop();
            }
            prev.push({arr[i], count});
            left[i] = count;
        }

        //filling right array
        for (int i = n - 1; i >= 0; i--)
        {
            int count = 1;
            while (!next.empty() && next.top().first >= arr[i])
            {
                count += next.top().second;
                next.pop();
            }
            next.push({arr[i], count});
            right[i] = count;
        }

        long long sum = 0;

        //left[i]*right[i] will be the number of subarrays in which arr[i] is minimum
        for (int i = 0; i < n; i++)    sum = (sum + arr[i] * 1LL * left[i] * right[i]) % mod;

        return sum;
    }
};
//Same approach as above but with shorter code
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr)
    {
        int n = arr.size(), mod = 1e9 + 7;
        stack<int>s;
        long ans = 0;

        for (int i = 0; i <= n; i++)
        {
            while (!s.empty() && (i == n or arr[s.top()] > arr[i]))
            {
                int j =  s.top();
                s.pop();
                int k = s.empty() ? -1 : s.top();
                ans += arr[j] * 1LL * (i - j) * (j - k);
                ans %= mod;
            }

            s.push(i);
        }

        return ans;
    }
};

//https://leetcode.com/problems/sum-of-subarray-minimums/discuss/257811/Python-O(n)-slightly-easier-to-grasp-solution-(explained)
//Using Stack
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr)
    {
        int n = arr.size(), mod = 1e9 + 7;
        stack<int>s;
        vector<long long>res(n);

        for (int i = 0; i < n; i++)
        {
            while (!s.empty() && arr[s.top()] > arr[i])  s.pop();

            int j = s.empty() ? -1 : s.top();
            res[i] = (j == -1 ? 0 : res[j]) + (i - j) * 1LL * arr[i];
            s.push(i);
        }

        long long sum = 0;

        for (int i = 0; i < n; i++)    sum = (sum + res[i]) % mod;
        return sum;
    }
};