//Using sorting
//Time complexity - O(nlogn + n)
//Space complexity - O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;

        for (int &num : nums)
        {
            if (ans != num)  return ans;
            ans++;
        }

        return nums.size();
    }
};

//Using Binary Search - preferred when input is already sorted
//Time complexity - O(nlogn + logn)
//Space complexity - O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int ans = nums.size(), low = 0, high = nums.size() - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] == mid)    low = mid + 1;

            else
            {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};

//Using frequency
//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size();
        vector<bool>isPresent(n + 1);

        for (int &num : nums)    isPresent[num] = true;

        for (int i = 0; i <= n; i++)   if (!isPresent[i])   return i;

        return -1;
    }
};

//Using Sum
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int n = nums.size(), totalSum = (n * (n + 1)) / 2;

        for (int &num : nums) totalSum -= num;
        /*
        To avoid overflow we can calculate totalSum on the fly
        int totalSum = 0;
        for (int i=0; i<n; i++)
        {
            totalSum -= num;
            totalSum += i;
        }
        totalSum += n;
        return totalSum;
        */

        return totalSum;
    }
};

//Using Xor property
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums)
    {
        int ans = nums.size(); // as index is from 0 to n-1
        int n = nums.size();

        for (int i = 0; i < n; i++)
        {
            ans ^= i;
            ans ^= nums[i];
        }

        return ans;
    }
};