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
	char s;
	unordered_map<char, Node*> children;
	string word;
	bool isTerminal;

	Node(char s)
	{
		this->s = s;
		isTerminal = false;
		word = ""; //will update only at the leaf node
	}
};

class Trie {
public:
	Node *root;

	Trie()
	{
		root = new Node('\0');
	}

	void addWord(string word)
	{
		Node *temp = root;
		for (auto ch : word)
		{
			if (temp->children.count(ch) == 0)
			{
				temp->children[ch] = new Node(ch);
			}

			temp = temp->children[ch];
		}

		//last node
		temp->isTerminal = true;
		temp->word = word;
	}

};

//Main algorithm (8-way dfs + trie guided search)
void dfs(vector<vector<char>>&board, Node *node, int i, int j, vector<vector<bool>>&visited, unordered_set<string>&output, int m, int n)
{
	//base case
	char ch = board[i][j];
	if (node->children.count(ch) == 0)
	{
		return;
	}

	//otherwise trie contains this node
	visited[i][j] = true;
	node = node->children[ch];

	//if it is a terminal node in the trie
	if (node->isTerminal)
	{
		output.insert(node->word);
	}

	//explore the 8 neighbours
	int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
	int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1};

	for (int k = 0; k < 8; k++)
	{
		int ni = i + dx[k];
		int nj = j + dy[k];

		//if it is in bounds and is not visited
		if (ni >= 0 and nj >= 0 and ni < m and nj < n and !visited[ni][nj])
		{
			dfs(board, node, ni, nj, visited, output, m, n);
		}
	}

	//reset the visited cell after every call - Backtracking
	visited[i][j] = false;
}

int main()
{
	starter();

	int m, n;
	cin >> m >> n;

	vector<vector<char>>board(m, vector<char>(n));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	int k;
	cin >> k;
	vector<string>words(k);
	cin >> words;

	//1. Trie
	Trie t;
	for (auto w : words)
	{
		t.addWord(w);
	}

	//2. Take a container to store words that are found in dfs search
	unordered_set<string>output; //To avoid duplicates

	//3. 8-way DFS search from every cell
	vector<vector<bool>>visited(m, vector<bool>(n, false));
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			dfs(board, t.root, i, j, visited, output, m, n);
		}
	}

	//4. Print the output
	for (auto word : output)	cout << word << " ";

	return 0;
}