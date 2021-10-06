#include<bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> wordList)
{
	int n = wordList.size();

	unordered_map<string, bool>visited;

	for (int i = 0; i < n; i++)
	{
		visited[wordList[i]] = false;
	}

	queue<string>q;
	q.push(beginWord);
	visited[beginWord] = true;

	int level = 0;

	while (!q.empty())
	{
		level++;

		int sz = q.size(); //number of nodes in current level

		for (int i = 0; i < sz; i++) //iterating over the current level nodes
		{
			string s = q.front();
			q.pop();

			if (s == endWord) return level;

			for (int j = 0; j < s.size(); j++) //iterating over the nbrs by changing single char if present
			{
				char ch = s[j];

				for (int k = 0; k < 26; k++) //trying for every possibility a,b,...,z
				{
					s[j] = 'a' + k;

					if (visited.find(s) != visited.end() && visited[s] == false)
					{
						q.push(s);
						visited[s] = true;
					}
				}

				s[j] = ch;
			}

		}

	}

	return 0;
}