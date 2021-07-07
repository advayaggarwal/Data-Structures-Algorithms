//Time complexity - O(nlogn), n is the length of string
//Space complexity - O(1)
class Solution {
public:
	bool isAnagram(string s, string t) {

		if (s.size() != t.size()) 	return false;
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
	}
};


//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
	bool isAnagram(string s, string t) {

		if (s.size() != t.size()) 	return false;
		unordered_map<char, int>m;

		for (char c : s)   m[c]++; //stored the frequency of each and every char in map

		for (char c : t)   m[c]--; //marked as seen

		//if frequency of every char is 0 it means anagram, else not
		//traverse through the map

		for (auto e : m)
		{
			if (e.second != 0) return false;
		}
		return true;
	}
};


//Time complexity - O(n)
//Space complexity - O(n)
class Solution {
public:
	bool isAnagram(string s, string t) {

		if (s.size() != t.size()) 	return false;

		unordered_map<char, int>m;

		for (char c : s)   m[c]++; //stored the frequency of each and every char in map

		for (char c : t)
		{
			m[c]--; //marked as seen
			if (m[c] < 0)	return false; //no need to check further
		}

		//if frequency of every char is 0 it means anagram, else not
		return true;
	}
};


//Instead of map we can make frequency array of size 26 as question says string contains only lowercase Engligh letters
//Time complexity - O(n)
//Space complexity - O(1), as 26 size array can be considered as constant, it will not increase with the size of input
class Solution {
public:
	bool isAnagram(string s, string t) {

		if (s.size() != t.size()) 	return false;
		vector<int>frequency(26, 0);

		for (char c : s)   frequency[c - 'a']++; //stored the frequency of each and every char in vector

		for (char c : t)
		{
			frequency[c - 'a']--; //marked as seen
		}

		//if frequency of every char is 0 it means anagram, else not
		for (int i = 0; i < 26; i++) if (frequency[i] != 0) return false;
		return true;
	}
};