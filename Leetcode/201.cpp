//Time complexity - O(n) -> TLE
//Space complexity - O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int ans = left;

        for (int i = left + 1; i <= right; i++)  ans &= i;

        return ans;
    }
};

//Idea - Bitwise AND of two numbers will always be less than or equal to the smaller number
//Time complexity - O(logn)
//Space complexity - O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right)
    {
        while (right > left)
        {
            right &= (right - 1);
        }

        return left & right;
    }
};

//In one word, this problem is asking us to find the common prefix of left and right 's binary code.
//Time complexity - O(32), i.e O(logn)
//Space complexity - O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int ans = 0;

        for (int bit = 30; bit >= 0; bit--)
        {
            if ((left & (1 << bit)) != (right & (1 << bit))) break; //from here it will contribute nothing to the answer

            else //this bit is same in both left and right
            {
                ans |= (left & (1 << bit)); //&& with left because this bit can be 0 in both left and right
            }
        }

        return ans;
    }
};

//Time complexity - O(32), i.e O(logn)
//Space complexity - O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right)
    {
        int rshift = 0;
        while (left != right)
        {
            left >>= 1;
            right >>= 1;
            rshift++;
        }

        return left << rshift;
    }
};