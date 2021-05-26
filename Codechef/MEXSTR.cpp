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

set<int>sub;

void solve(string s, string op)
{
	if (s.size() == 0)
	{
		if (op == "")	return;
		int x = std::stoi(op, nullptr, 2);
		sub.insert(x);
		return;
	}

	solve(s.substr(1), op);
	solve(s.substr(1), op + s[0]);
}

void decToBinary(int n)
{
	int binaryNum[32];
	int i = 0;
	while (n > 0) {
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}
	for (int j = i - 1; j >= 0; j--)
		cout << binaryNum[j];
}


int main()
{
	starter();
	test_cases(t)
	{
		string s;
		cin >> s;
		string op = "";
		solve(s, op);
		//int x = stoi(s, nullptr, 2);
		for (int i = 0; i < 1 << (s.size()); i++)
		{
			if (sub.find(i) == sub.end())
			{
				//cout << i << endl;
				if (i == 0)	cout << 0 << endl;
				else
				{
					decToBinary(i);
					cout << endl;
				}
				break;
			}
		}

		sub.clear();
	}
	return 0;
}