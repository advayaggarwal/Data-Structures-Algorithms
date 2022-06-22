//Time complexity - O(nlogn)
//Space complexity - O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        sort(nums.begin(), nums.end(), [&](int &a, int &b) {
            return !(a & 1) > !(b & 1);
        });

        return nums;
    }
};

//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        int n = nums.size();
        vector<int>result(n);
        int i = 0, j = n - 1;
        for (int k = 0; k < n; k++)
        {
            if (nums[k] % 2 == 0)  result[i++] = nums[k];
            else result[j--] = nums[k];
        }

        return result;
    }
};

//Same as partition method in quicksort
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums)
    {
        int n = nums.size();
        int j = -1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] % 2 == 0)
            {
                j++;
                swap(nums[i], nums[j]);
            }
        }

        return nums;
    }
};