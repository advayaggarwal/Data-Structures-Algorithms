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

//Each number in vector v may only be used once in the combination.

//Pick and not pick method
void combinationSum2(vi &v, int index, int target, vi &sol, vector<vi>&res, bool prev_taken)
{
	if (target == 0)
	{
		res.push_back(sol);
		return ;
	}

	if (index == v.size() or target < 0)	return ;

	//don't pick the current element
	combinationSum2(v, index + 1, target, sol, res, false);

	if (index > 0 && v[index] == v[index - 1] and !prev_taken)	return;
	//pick the current element
	sol.push_back(v[index]);
	combinationSum2(v, index + 1, target - v[index], sol, res, true);
	sol.pop_back();
}

//Loop over elements method
void CombinationSum2(vi &v, int index, int target, vi &sol, vector<vi>&res)
{
	if (target == 0)
	{
		res.push_back(sol);
		return;
	}

	if (target < 0)	return;

	for (int i = index; i < v.size(); i++)
	{
		if (i > index and v[i] == v[i - 1])	continue;

		sol.push_back(v[i]);
		CombinationSum2(v, i + 1, target - v[i], sol, res);
		sol.pop_back();
	}
}

int main()
{
	starter();

	int n, target;
	cin >> n >> target;

	vi v(n);
	cin >> v;

	vector<vi>res;

	vi sol;
	sort(v.begin(), v.end());

	combinationSum2(v, 0, target, sol, res, false);

	CombinationSum2(v, 0, target, sol, res);

	for (auto arr : res)
	{
		for (int e : arr)	cout << e << " ";
		cout << endl;
	}

	return 0;
}