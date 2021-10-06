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

//Each number in vector v may can be used more than once in the combination.
void combinationSum(vi &v, vi &sol, int target, int index, vector<vi>&res)
{

	if (target == 0)
	{
		res.push_back(sol);
		return;
	}

	if (index == v.size() or target < 0)	return ;

	//skip the current element, increment the index
	combinationSum(v, sol, target, index + 1, res);

	//take the current element, don't increment index, as we can again take it
	sol.push_back(v[index]);
	combinationSum(v, sol, target - v[index], index, res);
	sol.pop_back();
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
	combinationSum(v, sol, target, 0, res);

	for (auto arr : res)
	{
		for (int x : arr)	cout << x << " ";
		cout << endl;
	}
	return 0;
}