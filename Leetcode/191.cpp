//Time complexity - O(k), where k is #set bits
//Space complexity - O(1)
class Solution {
public:
	int hammingWeight(uint32_t n) {

		int count = 0;
		while (n)
		{
			n = n & (n - 1);
			count++;
		}

		return count;
	}
};

//Time complexity - O(32) or O(logn), i.e. max bits in n
//Space complexity - O(1)
class Solution {
public:
	int hammingWeight(uint32_t n)
	{
		int count = 0;

		for (int i = 0; i < 32; i++)
		{
			if (n >> i & 1)    count++;
		}

		return count;
	}
};

//Using STL
class Solution {
public:
	int hammingWeight(uint32_t n)
	{
		return __builtin_popcount(n);
	}
};