/*
	AUTHOR:			ADVAY AGGARWAL
	INSTITUTION:	IIIT DHARWAD
*/
#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long int
#define test_cases(x)	int x; cin>>x; while(x--)
#define vi vector<int>
#define setbits(x)      __builtin_popcountll(x)
#define endl "\n"

void starter()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#ifndef ONLINE_JUDGE
	//for getting input from input.txt
	freopen("input.txt", "r", stdin);
	//for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
}

map<char, int>ma;

bool is_valid(string s, int h, int m)
{
	if (ma[s[0]] == -1 || ma[s[1]] == -1 || ma[s[3]] == -1 || ma[s[4]] == -1) return false;
	int x = ma[s[3]] + (10 * ma[s[4]]);
	int y = ma[s[0]] + (10 * ma[s[1]]);
	if (x < h && y < m)	return true;
	return false;

}

int main()
{
	starter();

	ma['0'] = 0;
	ma['1'] = 1;
	ma['2'] = 5;
	ma['5'] = 2;
	ma['8'] = 8;
	ma['3'] = -1;
	ma['4'] = -1;
	ma['6'] = -1;
	ma['7'] = -1;
	ma['9'] = -1;
	test_cases(t)
	{
		int h, m;
		cin >> h >> m;
		string s;
		cin >> s;
		if (is_valid(s, h, m)) cout << s << endl;
		else
		{
			int hh = (s[1] - '0') + (10 * (s[0] - '0'));
			int mm = (s[4] - '0') + (10 * (s[3] - '0'));
			//cout << hh << " " << mm << endl;
			while (hh < h && mm < m )
			{
				string s = to_string(hh) + ":" + to_string(mm);
				if (hh < 10 && mm >= 10)
				{
					s = "0" + to_string(hh) + ":" + to_string(mm);
				}
				else if (hh > 9 && mm < 10)
				{
					s = to_string(hh) + ":" + "0" + to_string(mm);
				}
				else if (hh < 10 && mm < 10)
				{
					s = "0" + to_string(hh) + ":" + "0" + to_string(mm);
				}
				//cout << s << endl;

				if (is_valid(s, h, m))
				{
					cout << s << endl;
					break;
				}
				else {
					if (mm == m - 1)
					{
						if (hh < h - 1)hh++;
						else hh = 0;
						mm = 0;
					}
					else if (mm < m - 1) mm++;
				}
				// if (hh == h - 1)
				// {
				// 	hh = 0;
				// 	mm = 0;
				// }
			}
		}
	}
	return 0;
}