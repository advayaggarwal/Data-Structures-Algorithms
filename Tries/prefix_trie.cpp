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
	char data;
	unordered_map<char, Node*>m;
	bool isTerminal;


	Node(char d)
	{
		data = d;
		isTerminal = false;
	}

};

class Trie {
public:
	Node *root;

	Trie()
	{
		root = new Node('\0'); //init with NULL
	}

	void insert(string word) //O(word.size())
	{
		Node *temp = root;
		for (auto ch : word)
		{
			if (temp->m.find(ch) == temp->m.end())
			{
				Node *n = new Node(ch);
				temp->m[ch] = n;
			}

			temp = temp->m[ch];
		}

		temp->isTerminal = true;
	}

	bool search(string word) //O(word.size())
	{
		Node *temp = root;
		for (auto ch : word)
		{
			if (temp->m.find(ch) == temp->m.end())	return false;
			temp = temp->m[ch];
		}

		return temp->isTerminal;
	}

};

int main()
{
	starter();

	int n, q;
	cin >> n >> q;

	vector<string>words(n);
	cin >> words;

	Trie t;
	for (auto w : words)	t.insert(w);

	string search_word;

	while (q--)
	{
		cin >> search_word;
		if (t.search(search_word))	cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}