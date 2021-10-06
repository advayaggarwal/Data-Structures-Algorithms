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

/*
	You are given a running stream of integers. Write an efficient algorithm to
	output median of numbers read so far after every input.
*/

//Time complexity - O(N*logN)
int main()
{
	starter();

	priority_queue<int> leftHeap; //Max Heap
	priority_queue<int, vi, greater<int>> rightHeap; //Min Heap

	int d;
	cin >> d;

	leftHeap.push(d);

	float med = d;
	cout << med << " "; //for 1st element it is the median

	cin >> d;

	while (d != -1) //input stream terminated by -1
	{
		//Left heap bigger or right heap bigger or both equal

		if (leftHeap.size() > rightHeap.size())
		{
			if (d > med)
			{
				rightHeap.push(d);
			}

			else //Have to do rebalancing of heaps
			{
				rightHeap.push(leftHeap.top());
				leftHeap.pop();
				leftHeap.push(d);
			}

			med = (leftHeap.top() + rightHeap.top()) / 2.0;
		}

		else if (leftHeap.size() == rightHeap.size())
		{
			if (d < med)
			{
				leftHeap.push(d);
				med = leftHeap.top();
			}

			else
			{
				rightHeap.push(d);
				med = rightHeap.top();
			}
		}

		else
		{
			if (d > med) //Have to do rebalancing of heaps
			{
				leftHeap.push(rightHeap.top());
				rightHeap.pop();
				rightHeap.push(d);
			}

			else
			{
				leftHeap.push(d);
			}

			med = (leftHeap.top() + rightHeap.top()) / 2.0;
		}

		cout << med << " ";

		cin >> d;
	}

	return 0;
}