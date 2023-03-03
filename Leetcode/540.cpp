/*
Binary Search -
The pairs which are on the left of the single element, will have the first element in an even position and the second element at an odd
position.
All the pairs which are on the right side of the single element will have the first position at an odd position and the second element
at an even position. Use this fact to decide whether to go to the left side of the array or the right side.

E = even, O = odd

1 1 2 3 3 4 4 8 8
E O E O E O E O E
    ^
    |

before element 2 -> E O E O ...
after element 2 -> O E O E ...
*/

//Time complexity - O(logn)
//Space complexity - O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums)
    {
        int lo = 0, hi = nums.size() - 1, ans = -1;

        while (lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;

            //if nums[mid] is single
            if ((mid <= 0 or (nums[mid - 1] != nums[mid])) && (mid >= nums.size() - 1 or (nums[mid + 1] != nums[mid])))    return nums[mid];

            //double
            else if (mid % 2 == 0)
            {
                if (nums[mid] == nums[mid + 1])    lo = mid + 1;
                else hi = mid - 1;
            }

            else
            {
                if (nums[mid] == nums[mid + 1])    hi = mid - 1;
                else lo = mid + 1;
            }
        }

        return -1;
    }
};