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

class Special_Stack
{
private:
	stack<ll>s;
	ll minEle;
public:
	void push(int x) {
		if (s.size() == 0)
		{
			s.push(1LL * x);
			minEle = 1LL * x;
			return;
		}
		else
		{
			if (x >= minEle)    s.push(x);
			else
			{
				s.push(2 * 1LL * x - minEle);
				minEle = 1LL * x;
			}
		}
	}

	void pop() {
		if (s.top() < minEle) {
			minEle = 2 * 1LL * minEle - s.top();
		}
		s.pop();
	}

	int top() {
		if (s.size() == 0)	return -1;
		if (s.top() <= minEle)   return minEle;
		return (s.top());
	}

	int get_min() {

		return minEle;
	}

};

int main()
{
	starter();
	Special_Stack s;
	s.push(2);
	cout << s.get_min() << endl;
	s.push(0);
	s.push(3);
	s.push(0);
	cout << s.get_min() << endl;
	s.pop();
	cout << s.get_min() << endl;
	s.pop();
	cout << s.get_min() << endl;
	s.pop();
	cout << s.get_min() << endl;

	return 0;
}