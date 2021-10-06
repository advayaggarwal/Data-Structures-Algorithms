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
#define vvi vector<vi>

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

class Node {
public:
	Node *left; //for 0
	Node *right; //for 1

};

class Trie {
	Node *root;

public:
	Trie()
	{
		root = new Node();
	}

	void insert(int n) //O(32) ~ O(1)
	{
		Node *temp = root;
		//insert bits of that number in the trie
		for (int i = 31; i >= 0; i--)
		{
			int bit =  (n >> i) & 1;

			if (bit == 0)
			{
				if (temp->left == NULL)
				{
					temp->left = new Node();
				}
				temp = temp->left;
			}

			else
			{
				if (temp->right == NULL)
				{
					temp->right = new Node();
				}
				temp = temp->right;
			}
		}
	}

	int max_xor_helper(int value) //O(32) ~ O(1)
	{
		int ans = 0;
		Node *temp = root;

		for (int i = 31; i >= 0; i--)
		{
			int bit = (value >> i) & 1;

			if (bit == 0)
			{
				//look for 1, as 0^1 = 1
				if (temp->right != NULL) //got the 1
				{
					temp = temp->right;
					ans += (1 << i);
				}

				else	temp = temp->left;
			}

			else //1
			{
				//look for 0
				if (temp->left != NULL)
				{
					temp = temp->left;
					ans += (1 << i);
				}

				else temp = temp->right;
			}
		}
		return ans;
	}

	int max_xor(vi &input, int n) //O(n)
	{
		int max_xor = 0;

		for (int i = 0; i < n; i++)
		{
			insert(input[i]);
			int current_xor = max_xor_helper(input[i]);
			max_xor = max(current_xor, max_xor);
		}

		return max_xor;
	}
};

/*
Given an array, find the maximum XOR that you can form by picking any two numbers from the array
*/

int main()
{
	starter();

	int n;
	cin >> n;

	vi arr(n);
	cin >> arr;

	Trie t;

	cout << t.max_xor(arr, n);

	return 0;
}