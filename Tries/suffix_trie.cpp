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

class SuffixTrie {
public:
	Node *root;

	SuffixTrie()
	{
		root = new Node('\0'); //init with NULL
	}

	void insert_helper(string word) //O(word.size())
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

	void insert(string word) //O((word.size())^2 * k), where k is avg length of suffix
	{
		//pick all suffix substrings from (i, n-1) and call insert_helper

		for (int i = 0; i < word.size(); i++)
		{
			insert_helper(word.substr(i));
		}
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

	string s;
	cin >> s;

	SuffixTrie t;
	t.insert(s);

	//To check if insertion is correct
	vector<string>suffix;

	for (int i = 0; i < s.size(); i++)
	{
		suffix.push_back(s.substr(i)); //pushing all the suffix of s in suffix vector
	}

	//Checking if all the suffix are present in SuffixTrie or not
	for (int i = 0; i < suffix.size(); i++)
	{
		cout << suffix[i] << " " << t.search(suffix[i]) << endl;
	}

	return 0;
}