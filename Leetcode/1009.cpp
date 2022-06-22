class Solution {
public:
    int bitwiseComplement(int n)
    {
        int m = 1;

        while (m < n)    m = (m << 1) + 1;
        return n ^ m;
    }
};

//Time complexity - O(1)
//Space complexity - O(1)
// Get all-1 mask by spreading 1 from most significant to the rest:
class Solution {
public:
    int findComplement(int num)
    {
        if (num == 0) return 1;
        int mask = num;
        mask |= mask >> 1;
        mask |= mask >> 2;
        mask |= mask >> 4;
        mask |= mask >> 8;
        mask |= mask >> 16;
        return num ^ mask;
    }
};