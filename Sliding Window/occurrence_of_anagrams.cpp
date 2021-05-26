class Solution {
public:
	int search(string pat, string txt) {
		int k = pat.size();
		int n = txt.size();
		int i = 0, j = 0;
		unordered_map<char, int>m;
		for (char c : pat) m[c]++;
		int ans = 0;
		while (j < n)
		{

			m[txt[j]]--;
			if (j - i + 1 < k) j++;

			else
			{
				if (countZero(m))
				{
					ans++;
				}
				m[txt[i]]++;
				i++;
				j++;

			}
		}

		return ans;
	}


	bool countZero(unordered_map<char, int>&m)
	{
		for (auto e : m)
		{
			if (e.second != 0)    return false;
		}

		return true;
	}


};