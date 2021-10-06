//Recursive Backtracking
//Time complexity - O(2^n)
//Space complexity - O(n) as Recursion requires additional memory for the stack frames

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        return helper(nums, 0, n - 1);
    }

    bool helper(vector<int>& nums, int i, int j)
    {
        if (i == j)    return true;

        for (int k = 1; k <= nums[i]; k++)
        {
            if (helper(nums, i + k, j)) return true;
        }

        return false;
    }
};


//Top Down DP
//Time complexity - O(n^2) -> TLE
//Space complexity - O(2n) as Recursion requires additional memory for the stack frames

class Solution {

public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        dp[n - 1] = 1;
        return  helper(nums, 0, dp);
    }

    bool helper(vector<int>& nums, int i, vector<int>&dp)
    {
        if (dp[i] != -1)
        {
            return dp[i] == 1 ? true : false;
        }

        int furthestJump = min(i + nums[i], (int)nums.size() - 1);

        for ( int k = furthestJump; k >= i + 1; k--)
        {
            if (helper(nums, k, dp))
            {
                dp[i] = 1;
                return true;
            }

        }
        dp[i] = 0;
        return false;
    }

};


//Bottom Up DP
//Time complexity - O(n^2) faster than top down
//Space complexity - O(n)

//The observation to make here is that we only ever jump to the right.
//This means that if we start from the right of the array,
//every time we will query a position to our right,
//that position has already be determined as being able to reach end or not. i.e. 0 or 1
//This means we don't need to recurse anymore, as we will always hit the dp table.

class Solution {

public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        dp[n - 1] = 1;

        for (int i = n - 2; i >= 0; i--)
        {
            int furthest = min(i + nums[i], n - 1);

            for (int j = i + 1; j <= furthest; j++)
            {
                if (dp[j] == 1)
                {
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[0] == 1;
    }
};


//Greedy
//Time complexity - O(n)
//Space complexity - O(1)

/*From a given position, when we try to see if we can jump to a GOOD position, we only ever use one - the first one
(see the break statement). In other words, the left-most one. If we keep track of this left-most GOOD position as a separate variable,
we can avoid searching for it in the array. Not only that, but we can stop using the array altogether.

Iterating right-to-left, for each position we check if there is a potential jump that reaches a
GOOD index (currPosition + nums[currPosition] >= leftmostGoodIndex). If we can reach a GOOD index, then our position is itself GOOD.
Also, this new GOOD position will be the new leftmost GOOD index. Iteration continues until the beginning of the array.
If first position is a GOOD index then we can reach the last index from the first position.
*/

class Solution {

public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int lastGood = n - 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (i + nums[i] >= lastGood) lastGood = i;
        }

        return lastGood == 0;
    }
};

//Peak valley approach
//Refer TechDose's video
//Time complexity - O(n)
//Space complexity - O(1)

class Solution {

public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > maxReach)  return false;
            maxReach = max(maxReach, i + nums[i]);
        }

        return true;
    }
};