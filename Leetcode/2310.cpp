/*
https://www.youtube.com/watch?v=LiYMFscvlKU
Assume the size of the set is n, and the numbers in the set are A1, A2,..., An

A1 + A2 + ... + An = sum
All numbers must have k as the unit digit
So A1 + A2 + ... + An = n*k + 10*(a1 + a2 + .. + an) = sum

Which (a1 + a2 + .. + an) can be any number.
(num %10) == (n*k)%10
*/
//Time complexity - O(1)
//Space complexity - O(1)
class Solution {
public:
    int minimumNumbers(int num, int k)
    {
        if (num == 0)    return 0;

        for (int i = 1; i * k <= num && i <= 10; i++)
        {
            if ((i * k) % 10 == num % 10)   return i;
        }

        return -1;
    }
};