//Approach 1
class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string>res;
		for (int i = 1; i <= n; i++)
		{
			if (i % 15 == 0)	res.push_back("FizzBuzz");
			else if (i % 5 == 0)	res.push_back("Buzz");
			else if (i % 3 == 0)	res.push_back("Fizz");
			else res.push_back(to_string(i));
		}

		return res;
	}
};


//Approach 2
class Solution {
public:
	vector<string> fizzBuzz(int n) {
		vector<string>res;
		for (int i = 1; i <= n; i++)
		{
			string ans = "";
			if (i % 3 == 0)	ans += "Fizz";
			if (i % 5 == 0)	ans += "Buzz";
			if (ans == "")	ans += to_string(i);

			res.push_back(ans);
		}

		return res;
	}
};