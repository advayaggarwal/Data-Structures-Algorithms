//Time complexity - O(nlogn)
//Space complexity - O(1)
class Solution {
public:
    bool sumOfNumberAndReverse(int num)
    {
        for (int i = 0; i <= num; i++)
        {
            if (i + reverse(i) == num)  return true;
        }
        return false;
    }

    int reverse(int num)
    {
        int r = 0;

        while (num)
        {
            r = r * 10 + (num % 10);
            num /= 10;
        }

        return r;
    }
};