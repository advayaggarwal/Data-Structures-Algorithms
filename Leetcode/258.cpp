//Time complexity - O(logn)
//Space complexity - O(1)
class Solution {
public:
    int addDigits(int num)
    {
        int digitalRoot = 0;
        while (num)
        {
            digitalRoot += num % 10;
            num /= 10;

            if (num == 0 && digitalRoot > 9)
            {
                num = digitalRoot;
                digitalRoot = 0;
            }
        }

        return digitalRoot;
    }
};

//Time complexity - O(1)
//Space complexity - O(1)
class Solution {
public:
    int addDigits(int num)
    {
        if (num == 0)    return 0;
        int ans =  num % 9;
        return ans ? ans : 9;
    }
};