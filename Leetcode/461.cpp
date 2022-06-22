//Hamming distance is equal to number of set bits in x^y (ith bit will be 1 if ith bit differs in x and y)
class Solution {
public:
    int hammingDistance(int x, int y)
    {
        int n = x ^ y;
        return __builtin_popcount(n);
    }
};