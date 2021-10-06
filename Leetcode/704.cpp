//Iterative BS
class Solution {
public:
    int search(vector<int>& nums, int target) {

        int n = nums.size();
        int start = 0, end = n - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) start = mid + 1;
            else    end = mid - 1;
        }

        return -1;
    }
};

//Recursive BS
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return bs(0, n - 1, nums, target);
    }

    int bs(int start, int end, vector<int>&nums, int target)
    {
        if (start > end) return -1;

        int mid = start + (end - start) / 2;

        if (nums[mid] == target) return mid;

        else if (nums[mid] < target) return bs(mid + 1, end, nums, target);

        else return bs(start, mid - 1, nums, target);
    }

};

//Using STL

class Solution {
public:
    int search(vector<int>& nums, int target) {

        auto it = lower_bound(nums.begin(), nums.end(), target);

        if ((it != nums.end()) && (*it == target))  return it - nums.begin();

        return -1;

    }
};