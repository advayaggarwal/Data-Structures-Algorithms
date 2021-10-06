/*
	AUTHOR:			ADVAY AGGARWAL
*/

#include<bits/stdc++.h>
using namespace std;
#define mod		1000000007 //1e9+7	ans%mod
#define ll 	long long int
#define test_cases(x)	int x; cin>>x; while(x--)
#define vi vector<int>
#define setbits(x)      __builtin_popcountll(x)
#define endl "\n"
#define pii pair<int,int>


template <typename Type>
istream &operator>>(istream &in, vector<Type> &vec) {
	int n = vec.size();
	for (int i = 0; i < n; i++)	in >> vec[i];
	return in;
}

template <typename Type>
ostream &operator<<(ostream &out, vector<Type> &vec) {
	for (auto &val : vec)	out << val << " ";
	return out;
}

void starter()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

bool compareBoxes(const vi &b1, const vi &b2)
{
	return b1[2] < b2[2];
}

bool canStack(vi box_j, vi box_i)
{
	return box_j[0] < box_i[0] and box_j[1] < box_i[1] and box_j[2] < box_i[2];
}

//Variation of LIS
int boxStacking(vector<vi>&boxes)
{
	int n = boxes.size();
	//1. Sorting based on height
	sort(boxes.begin(), boxes.end(), compareBoxes);

	//2. DP

	vi dp(n, 0); //dp[i] represents the maximum height we can get considering ith box as the base

	//Init the dp vector with the height of each box
	for (int i = 0; i < n; i++)
	{
		dp[i] = boxes[i][2]; //height of ith box
	}

	for (int i = 1; i < n; i++) //Considering ith box as the base
	{
		for (int j = 0; j < i; j++)
		{
			if (canStack(boxes[j], boxes[i]))dp[i] = max(dp[i], boxes[i][2] + dp[j]); //if jth box can be stacked onto the top of ith box
		}
	}
	return *max_element(dp.begin(), dp.end()); //return the max height
}

int main()
{
	starter();

	int n;
	cin >> n;

	vector<vi>boxes(n, vi(3)); //{length, breadth, height}
	cin >> boxes;

	cout << boxStacking(boxes);

	return 0;
}