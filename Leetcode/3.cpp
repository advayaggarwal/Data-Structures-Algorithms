//Brute Force
//Time complexity - O(n^2)
//Space complexity - O(256)
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int n = s.size();

		int ans = INT_MIN;

		for (int i = 0; i < n; i++)
		{
			vector<int>freq(256, 0);
			bool flag = false;
			for (int j = i; j < n; j++)
			{
				freq[(int)s[j]]++;
				if (freq[(int)s[j]] > 1) flag = true;

				if (!flag)   ans = max(ans, j - i + 1);
			}
		}

		return ans == INT_MIN ? 0 : ans;
	}
};


//Sliding Window
//Time complexity - O(n), 2 pass solution
//Space complexity - O(256)

class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		int n = s.size();
		unordered_map<char, int>m;
		int mx = INT_MIN;
		int i = 0, j = 0;
		while (j < n)
		{
			m[s[j]]++;
			if (m.size() == j - i + 1) //# unique chars equal to the window size i.e. all chars in that window are unique
			{
				mx = max(mx, j - i + 1);
				j++;
			}
			else
			{
				while (m.size() < j - i + 1) //window size is greater than # unique chars i.e. some chars are repeating
				{
					m[s[i]]--;
					if (m[s[i]] == 0)	m.erase(s[i]);
					i++;
				}

				if (m.size() == j - i + 1)	mx = max(mx, j - i + 1);
				j++;
			}
		}

		return mx == INT_MIN ? 0 : mx;
	}
};


//OR, shorter code

class Solution {
public:
	int lengthOfLongestSubstring(string s) {

		int n = s.size();
		int start = 0, end = 0;
		unordered_map<char, int>freq;
		int ans = INT_MIN;

		while (end < n)
		{
			freq[s[end]]++;

			while (freq[s[end]] > 1)
			{
				freq[s[start]]--;
				start++;
			}

			ans = max(ans, end - start + 1);
			end++;
		}

		return ans == INT_MIN ? 0 : ans;
	}
};


//The basic idea is, keep a hashmap which stores the characters in string as keys and their positions as values, and keep the two
//pointers which define the max substring. Move the right pointer to scan through the string, and meanwhile update the hashmap.
//If the character is already in the hashmap, then move the left pointer to the right of the same character last found.
//Note that the two pointers can only move forward.

//Time complexity - O(n), single pass solution

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int>m; //{char, index}

		int n = s.size();
		int i = 0, j = 0;
		int mx = 0;
		while (j < n)
		{
			if (m.find(s[j]) != m.end()) //already present in the map
			{
				i = max(i , m[s[j]] + 1); // if s[j] is in the current window, move i pointer to index of (s[j]) + 1
			}

			mx = max(mx, j - i + 1);
			m[s[j]] = j; //s[j] is last found at index j
			j++;
		}
		return mx;
	}
};