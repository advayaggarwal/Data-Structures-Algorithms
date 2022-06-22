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

//Node to store the data (Linked List)
class Node {
public:
	string key;
	int value;

	Node(string key, int value)
	{
		this->key = key;
		this->value = value;
	}
};

class LRUCache {
public:
	int maxSize;
	list<Node>l;
	unordered_map<string, list<Node>::iterator >m;

	LRUCache(int maxSize)
	{
		this->maxSize = maxSize > 1 ? maxSize : 1;
	}

	void insertKeyValue(string key, int value)
	{
		//2 cases
		if (m.count(key) != 0) //key already present, therefore update the value and make it most recently used
		{
			Node n(key, value); //making new node
			auto it = m[key];
			l.erase(it); //deleting the already existent node with same key
			l.push_front(n); //pushing the new node with new value
			m[key] = l.begin(); //updating the address
		}

		else //key not present, insert both into hashmap and list
		{
			//check if cache is full or not
			//if full remove least recently used item from cache (list + hashmap)
			if (l.size() == maxSize)
			{
				Node last = l.back();
				m.erase(last.key); //remove from hashmap
				l.pop_back(); //remove from list
			}

			Node n(key, value); //made a new node
			l.push_front(n); //push it into the head of the list
			m[key] = l.begin(); //insert into the hashmap
		}
	}

	int* getValue(string key) //returns the value if present and move that node to head of the list making it most recently used
	{
		//check if key is present
		if (m.count(key) != 0) //means key is present, also move this key to top of the list, as it is most recently used
		{
			auto it = m[key]; //it is now pointing to that particular node
			int value = m[key]->value;
			l.push_front(*it); //pushing that node(same key value pair, but will have different address) to the head of the list

			l.erase(it); //remove that particular node, after pushing it to the head

			m[key] = l.begin(); //now update the hashmap with the new address of that node, i.e. l.begin()

			return &l.begin()->value;
		}

		return NULL;
	}

	string mostRecentKey()
	{
		return l.begin()->key;
	}
};

int main()
{
	starter();

	LRUCache lru(3);
	lru.insertKeyValue("mango", 10);
	lru.insertKeyValue("apple", 20);
	lru.insertKeyValue("guava", 30);
	cout << lru.mostRecentKey() << endl;

	lru.insertKeyValue("mango", 40);
	cout << lru.mostRecentKey() << endl;

	lru.insertKeyValue("banana", 20);

	if (lru.getValue("apple") == NULL)
	{
		cout << "apple doesn't exist";
	}

	if (lru.getValue("guava") == NULL)
	{
		cout << "guava doesn't exist";
	}

	if (lru.getValue("banana") == NULL)
	{
		cout << "banana doesn't exist";
	}

	if (lru.getValue("mango") == NULL)
	{
		cout << "mango doesn't exist";
	}

	return 0;
}
