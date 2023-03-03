//Time complexity - O(log4n)
//Space complexity - O(1)
class Solution {
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)  return false;
        while (n % 4 == 0) n /= 4;
        return n == 1;
    }
};

//Observations
// 1. No of Set Bit Always Be Only ONE
// 2. That SetBit Possition Should Be always In odd Place [ starting from Left ] considering 1 based index
//Time complexity - O(1), as we only traverse max 32 bits
//Space complexity - O(1)
class Solution {
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)  return false;

        int countOf1 = 0, pos = 1, posOf1 = 0;

        while (n)
        {
            if (n & 1)
            {
                countOf1++;
                posOf1 = pos;
            }

            pos++;
            n >>= 1;
        }

        return (countOf1 == 1) && (posOf1 & 1);
    }
};

//Smart way of writing above code
class Solution {
public:
    bool isPowerOfFour(int n)
    {
        if (n <= 0)  return false;

        for (int i = 0; i < 32; i += 2)
        {
            if (n == (1 << i)) return true;
        }

        return false;
    }
};