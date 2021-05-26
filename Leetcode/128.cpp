/*
Before we do anything, we check for the base case input of the empty array. The longest sequence in an empty array is, of course, 0, so
we can simply return that. For all other cases, we sort nums and consider each number after the first (because we need to compare each
number to its previous number). If the current number and the previous are equal, then our current sequence is neither extended nor
broken, so we simply move on to the next number. If they are unequal, then we must check whether the current number extends the sequence
(i.e. nums[i] == nums[i-1] + 1). If it does, then we add to our current count and continue. Otherwise, the sequence is broken, so we
record our current sequence and reset it to 1 (to include the number that broke the sequence). And everytime we are updating
the longestStreak
*/

//Time complexity - O(nlogn)
//Space complexity - O(1)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)    return 0;

        sort(nums.begin(), nums.end());

        int longestStreak = 1, currentStreak = 1;

        for (int i = 1; i < n; i++)
        {
            if (nums[i] != nums[i - 1])
            {
                if (nums[i] == nums[i - 1] + 1)
                {
                    currentStreak++;
                }

                else
                {
                    currentStreak = 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }

        }

        return longestStreak;

    }
};


//Intution
/* We only attempt to build sequences from numbers that are not already part of a longer sequence. This is accomplished by first
ensuring that the number that would immediately precede the current number in a sequence is not present, as that number would
necessarily be part of a longer sequence. */

//Time complexity - O(n)

/*
Although the time complexity appears to be quadratic due to the while loop nested within the for loop, closer inspection reveals it
to be linear. Because the while loop is reached only when currentNum marks the beginning of a sequence
(i.e. currentNum-1 is not present in nums), the while loop can only run for nn iterations throughout the entire runtime of the algorithm.
This means that despite looking like O(n \cdot n)O(n⋅n) complexity, the nested loops actually run in O(n + n) = O(n)O(n+n)=O(n) time.
All other computations occur in constant time, so the overall runtime is linear.
*/

//Space complexity - O(n)


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>hash;
        for (int &num : nums) hash.insert(num);

        int longestStreak = 0; //0 for handling empty vector

        for (int &num : nums)
        {
            if (hash.find(num - 1) == hash.end())
            {
                int currentNum = num;
                int currentStreak = 1;
                while (hash.find(currentNum + 1) != hash.end())
                {
                    currentNum++;
                    currentStreak++;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};