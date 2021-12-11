//Time complexity - O(m+n)
//Space complexity - O(1)
class Solution {
public:
	string addStrings(string num1, string num2)
	{
		string res;
		int n1 = num1.size(), n2 = num2.size();

		int i = n1 - 1, j = n2 - 1;
		int carry = 0;

		while (i >= 0 or j >= 0 or carry)
		{
			int sum = 0;
			if (i >= 0)    sum += (num1[i--] - '0');
			if (j >= 0)    sum += (num2[j--] - '0');
			sum += carry;

			if (sum > 9)
			{
				res += to_string(sum % 10);
				carry = sum / 10;
			}

			else
			{
				res += to_string(sum);
				carry = 0;
			}
		}

		reverse(res.begin(), res.end());

		return res;
	}
};