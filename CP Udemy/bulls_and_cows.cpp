#include<bits/stdc++.h>
using namespace std;

string getHint(string secret, string guess)
{
	int n = secret.size();
	unordered_map<char, int>m;

	int bulls = 0, cows = 0;
	for (int i = 0; i < n; i++)
	{
		if (secret[i] == guess[i])   bulls++;
		m[secret[i]]++;
	}

	for (int i = 0; i < n; i++)
	{
		if (m.find(guess[i]) != m.end() && m[guess[i]] > 0)
		{
			cows++;
			m[guess[i]]--;
		}
	}

	cows -= bulls;

	return to_string(bulls) + "A" + to_string(cows) + "B";
}