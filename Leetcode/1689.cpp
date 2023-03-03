/*
Assume max digit in n is x.
Because deci-binary only contains 0 and 1,
we need at least x numbers to sum up a digit x.
*/
//Time complexity - O(n)
//Space complexity - O(1)
class Solution {
public:
	int minPartitions(string n) {
		int res = 0;
		for (int i = 0; i < (int)n.size(); i++)
		{
			res = max(res, n[i] - '0');
		}
		return res;
	}
};