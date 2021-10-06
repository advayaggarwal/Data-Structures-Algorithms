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


//Time complexity - O(N*2^N)
void subsetSum(vi &arr, int index, int target, vector<int>&sol, vector<vi> &res)
{
	//Base Case
	if (target == 0)
	{
		res.push_back(sol);
		return;
	}

	if (target < 0)	return;
	if (index == arr.size())	return;

	//skip the index th element
	subsetSum(arr, index + 1, target, sol, res);

	//take the index th element
	sol.push_back(arr[index]);
	subsetSum(arr, index + 1, target - arr[index], sol, res);
	sol.pop_back(); //backtracking
}

int countSubsets(vi &arr, int index, int n, int target)
{
	//Base Case
	if (index == n)
	{
		return target == 0 ? 1 : 0;
	}

	int exclusionCount = countSubsets(arr, index + 1, n, target);
	int inclusionCount = countSubsets(arr, index + 1, n, target - arr[index]);

	return inclusionCount + exclusionCount;

}

int main()
{
	starter();
	int n, target;
	cin >> n >> target;
	vi arr(n);
	cin >> arr;
	vector<vi> res;
	vector<int>sol;
	subsetSum(arr, 0, target, sol, res);
	cout << "No. of subsets having sum " << target << " are " << countSubsets(arr, 0, n, target) << endl;
	for (auto e : res)
	{
		for (int x : e)	cout << x << " ";
		cout << endl;
	}
	return 0;
}